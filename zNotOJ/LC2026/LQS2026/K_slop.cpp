#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx")

using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i=(a),_b=(b); i<=_b; ++i)
#define REP(i,n) for (int i=0,_n=(n); i<_n; ++i)

#define name "K"

static const int N = 100000 + 5;

// ============================================================
// Global
// ============================================================

int n, m;
int X[N], Y[N];

vector<int> bestAns;
ll bestCost = (1LL << 62);

mt19937_64 rng(
    chrono::steady_clock::now().time_since_epoch().count()
);

inline int distP(int a, int b) {
    return abs(X[a] - X[b]) + abs(Y[a] - Y[b]);
}

ll calcCost(const vector<int>& a) {
    ll res = 0;
    for (int i = 1; i < (int)a.size(); ++i)
        res += distP(a[i - 1], a[i]);
    return res;
}

void updateBest(const vector<int>& a, const char* tag = "") {
    ll c = calcCost(a);

    if (c < bestCost) {
        bestCost = c;
        bestAns = a;

        cerr << "[BEST] "
             << bestCost
             << "  (" << tag << ")\n";
    }
}

// ============================================================
// Hilbert curve
// ============================================================

static inline void rotHilbert(
    int s, int &x, int &y, int rx, int ry
) {
    if (ry == 0) {
        if (rx == 1) {
            x = s - 1 - x;
            y = s - 1 - y;
        }
        swap(x, y);
    }
}

static inline ull hilbertXY(int nside, int x, int y) {
    ull d = 0;

    for (int s = nside / 2; s > 0; s >>= 1) {
        int rx = (x & s) ? 1 : 0;
        int ry = (y & s) ? 1 : 0;

        d += 1ULL * s * s * ((3 * rx) ^ ry);

        rotHilbert(s, x, y, rx, ry);
    }

    return d;
}

// ============================================================
// Morton / Z-order
// ============================================================

static inline ull splitBits(unsigned int x) {
    ull v = x;

    v = (v | (v << 16)) & 0x0000FFFF0000FFFFULL;
    v = (v | (v << 8 )) & 0x00FF00FF00FF00FFULL;
    v = (v | (v << 4 )) & 0x0F0F0F0F0F0F0F0FULL;
    v = (v | (v << 2 )) & 0x3333333333333333ULL;
    v = (v | (v << 1 )) & 0x5555555555555555ULL;

    return v;
}

static inline ull mortonXY(int x, int y) {
    return splitBits((unsigned)x) |
          (splitBits((unsigned)y) << 1);
}

// ============================================================
// Ordering
// ============================================================

enum OrderType {
    HILBERT = 0,
    MORTON,
    SORT_X,
    SORT_Y,
    SORT_SUM,
    SORT_DIFF,
    SORT_X_REV,
    SORT_Y_REV
};

struct NodeKey {
    ull key;
    int id;
};

vector<int> makeOrder(OrderType type) {
    vector<NodeKey> a;
    a.reserve(n);

    if (type == HILBERT) {
        // Coordinates <= 1e6 < 2^20.
        const int SIDE = 1 << 20;

        for (int i = 1; i <= n; ++i) {
            a.push_back({
                hilbertXY(SIDE, X[i], Y[i]),
                i
            });
        }
    }
    else if (type == MORTON) {
        for (int i = 1; i <= n; ++i) {
            a.push_back({
                mortonXY(X[i], Y[i]),
                i
            });
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            ll k;

            if (type == SORT_X || type == SORT_X_REV)
                k = (ll)X[i] * 2000001LL + Y[i];

            else if (type == SORT_Y || type == SORT_Y_REV)
                k = (ll)Y[i] * 2000001LL + X[i];

            else if (type == SORT_SUM)
                k = (ll)X[i] + Y[i];

            else
                k = (ll)X[i] - Y[i] + 1000000LL;

            a.push_back({
                (ull)(k + 2000000000000LL),
                i
            });
        }
    }

    sort(a.begin(), a.end(), [&](const NodeKey& A, const NodeKey& B) {
        if (A.key != B.key) {
            if (type == SORT_X_REV || type == SORT_Y_REV)
                return A.key > B.key;
            return A.key < B.key;
        }

        // deterministic tie breaker
        return A.id < B.id;
    });

    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = a[i].id;

    return res;
}

// ============================================================
// Reverse order
// ============================================================

static inline void maybeReverse(vector<int>& a, bool rev) {
    if (rev)
        reverse(a.begin(), a.end());
}

// ============================================================
// Initial solution
//
// Pick one parity from a spatial ordering.
//
// Example:
//
// p0 p1 p2 p3 p4 p5
//
// take:
// p0 p2 p4
//
// This guarantees n/2 distinct points.
// ============================================================

vector<int> makeInitial(
    const vector<int>& ord,
    int parity
) {
    vector<int> ans;
    ans.reserve(m);

    for (int i = parity; i < n; i += 2)
        ans.push_back(ord[i]);

    return ans;
}

// ============================================================
// Fast local replacement
//
// Current sequence:
//
// a[0] a[1] ... a[i] ... a[m-1]
//
// Try replacing a[i] with an unused point.
//
// Candidate unused points are taken from a window around its
// original position in the spatial ordering.
//
// This is O(n * WINDOW).
// ============================================================

void localReplace(
    vector<int>& ans,
    const vector<int>& ord,
    int replaceWindow,
    int maxPass
) {
    vector<int> pos(n + 1, -1);
    vector<char> chosen(n + 1, 0);

    for (int i = 0; i < n; ++i)
        pos[ord[i]] = i;

    for (int id : ans)
        chosen[id] = 1;

    bool improved = true;

    for (int pass = 0; pass < maxPass && improved; ++pass) {
        improved = false;

        for (int i = 0; i < m; ++i) {
            int old = ans[i];

            ll oldCost = 0;

            if (i > 0)
                oldCost += distP(ans[i - 1], old);

            if (i + 1 < m)
                oldCost += distP(old, ans[i + 1]);

            int center = pos[old];

            int L = max(0, center - replaceWindow);
            int R = min(n - 1, center + replaceWindow);

            int bestId = -1;
            ll bestDelta = 0;

            for (int p = L; p <= R; ++p) {
                int nw = ord[p];

                if (chosen[nw])
                    continue;

                ll nwCost = 0;

                if (i > 0)
                    nwCost += distP(ans[i - 1], nw);

                if (i + 1 < m)
                    nwCost += distP(nw, ans[i + 1]);

                ll delta = nwCost - oldCost;

                if (delta < bestDelta) {
                    bestDelta = delta;
                    bestId = nw;
                }
            }

            if (bestId != -1) {
                chosen[old] = 0;
                chosen[bestId] = 1;
                ans[i] = bestId;

                improved = true;
            }
        }
    }
}

// ============================================================
// 2-opt.
//
// We do NOT scan all pairs.
//
// For every edge i, only inspect j in a small neighborhood.
// This is the key difference from the original O(n^2) code.
// ============================================================

void twoOpt(
    vector<int>& a,
    int window,
    int passes
) {
    if (m <= 3)
        return;

    for (int pass = 0; pass < passes; ++pass) {
        bool improved = false;

        for (int i = 0; i + 2 < m; ++i) {
            int maxJ = min(m - 2, i + window);

            for (int j = i + 2; j <= maxJ; ++j) {
                ll oldCost = 0;
                ll newCost = 0;

                // Edge before i.
                if (i > 0) {
                    oldCost += distP(a[i - 1], a[i]);
                    newCost += distP(a[i - 1], a[j]);
                }

                // Edge after j.
                if (j + 1 < m) {
                    oldCost += distP(a[j], a[j + 1]);
                    newCost += distP(a[i], a[j + 1]);
                }

                if (newCost < oldCost) {
                    reverse(a.begin() + i, a.begin() + j + 1);
                    improved = true;
                }
            }
        }

        if (!improved)
            break;
    }
}

// ============================================================
// Small random perturbation.
//
// Used only when we have enough time.
// ============================================================

void randomPerturb(
    vector<int>& a,
    const vector<int>& ord,
    int cnt
) {
    vector<int> pos(n + 1, -1);
    vector<char> chosen(n + 1, 0);

    for (int i = 0; i < n; ++i)
        pos[ord[i]] = i;

    for (int x : a)
        chosen[x] = 1;

    for (int z = 0; z < cnt; ++z) {
        int i = (int)(rng() % m);

        int old = a[i];
        int p = pos[old];

        int L = max(0, p - 50);
        int R = min(n - 1, p + 50);

        int nw = -1;

        for (int tries = 0; tries < 20; ++tries) {
            int q = L + (int)(rng() % (R - L + 1));

            if (!chosen[ord[q]]) {
                nw = ord[q];
                break;
            }
        }

        if (nw != -1) {
            chosen[old] = 0;
            chosen[nw] = 1;
            a[i] = nw;
        }
    }
}

// ============================================================
// More aggressive replacement.
//
// Candidate points are generated using several projections.
//
// This catches cases where Hilbert-near points aren't the best
// replacement.
// ============================================================

vector<int> globalXOrder, globalYOrder;

void extraReplace(
    vector<int>& a,
    int triesPerPoint
) {
    vector<char> chosen(n + 1, 0);

    for (int x : a)
        chosen[x] = 1;

    for (int i = 0; i < m; ++i) {
        int old = a[i];

        ll oldCost = 0;

        if (i)
            oldCost += distP(a[i - 1], old);

        if (i + 1 < m)
            oldCost += distP(old, a[i + 1]);

        int bestId = -1;
        ll bestDelta = 0;

        auto testCandidate = [&](int nw) {
            if (nw < 1 || nw > n)
                return;

            if (chosen[nw])
                return;

            ll nwCost = 0;

            if (i)
                nwCost += distP(a[i - 1], nw);

            if (i + 1 < m)
                nwCost += distP(nw, a[i + 1]);

            ll delta = nwCost - oldCost;

            if (delta < bestDelta) {
                bestDelta = delta;
                bestId = nw;
            }
        };

        // Random global samples.
        for (int z = 0; z < triesPerPoint; ++z) {
            int id = 1 + (int)(rng() % n);
            testCandidate(id);
        }

        if (bestId != -1) {
            chosen[old] = 0;
            chosen[bestId] = 1;
            a[i] = bestId;
        }
    }
}

// ============================================================
// Candidate processing
// ============================================================

void processOrder(
    vector<int> ord,
    const string& nameOrder,
    chrono::steady_clock::time_point startTime,
    long long timeLimitMs
) {
    for (int rev = 0; rev < 2; ++rev) {
        maybeReverse(ord, rev);

        for (int parity = 0; parity < 2; ++parity) {
            if (chrono::duration_cast<chrono::milliseconds>(
                    chrono::steady_clock::now() - startTime
                ).count() > timeLimitMs)
                return;

            vector<int> ans = makeInitial(ord, parity);

            updateBest(
                ans,
                (nameOrder + "_initial").c_str()
            );

            // ------------------------------------------------
            // Main local replacement.
            // ------------------------------------------------

            localReplace(
                ans,
                ord,
                20,
                2
            );

            updateBest(
                ans,
                (nameOrder + "_replace20").c_str()
            );

            // ------------------------------------------------
            // Local 2-opt.
            // ------------------------------------------------

            twoOpt(
                ans,
                32,
                2
            );

            updateBest(
                ans,
                (nameOrder + "_2opt32").c_str()
            );

            // Slightly wider replacement.
            localReplace(
                ans,
                ord,
                50,
                1
            );

            updateBest(
                ans,
                (nameOrder + "_replace50").c_str()
            );

            // Another short 2-opt.
            twoOpt(
                ans,
                64,
                1
            );

            updateBest(
                ans,
                (nameOrder + "_2opt64").c_str()
            );
        }
    }
}

// ============================================================
// Randomized polishing of the current best.
//
// We keep the sequence, perturb a few selected points, then
// locally optimize again.
// ============================================================

void polish(
    chrono::steady_clock::time_point startTime,
    long long timeLimitMs,
    const vector<int>& ord
) {
    if (bestAns.empty())
        return;

    int iteration = 0;

    while (true) {
        ll elapsed =
            chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now() - startTime
            ).count();

        if (elapsed >= timeLimitMs)
            break;

        ++iteration;

        vector<int> cur = bestAns;

        int perturb = 2 + (int)(rng() % 8);

        randomPerturb(cur, ord, perturb);

        twoOpt(cur, 24, 1);

        localReplace(cur, ord, 30, 1);

        twoOpt(cur, 40, 1);

        updateBest(cur, "random_polish");

        if ((iteration & 15) == 0) {
            cerr << "[POLISH] iter=" << iteration
                 << " best=" << bestCost
                 << " time=" << elapsed << "ms\n";
        }
    }
}

// ============================================================
// Special cases
// ============================================================

void solveSmall() {
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    if (n == 2) {
        cout << 1 << '\n';
        return;
    }
}

// ============================================================
// Main
// ============================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);

    int testId;

    cin >> testId;
    cin >> n;

    FOR(i, 1, n) {
        cin >> X[i] >> Y[i];
    }

    if (n <= 2) {
        solveSmall();
        return 0;
    }

    m = n / 2;

    auto startTime = chrono::steady_clock::now();

    // --------------------------------------------------------
    // Time limit.
    //
    // Original code uses:
    //
    //     10 * 60000 ms
    //
    // = 10 minutes.
    //
    // Keep the same limit.
    // --------------------------------------------------------

    const long long TIME_LIMIT_MS = 3LL * 60000LL;

    cerr << "========================================\n";
    cerr << "Test = " << testId << '\n';
    cerr << "n    = " << n << '\n';
    cerr << "m    = " << m << '\n';
    cerr << "time = " << TIME_LIMIT_MS << " ms\n";
    cerr << "========================================\n";

    // --------------------------------------------------------
    // Precompute ordinary orders.
    // --------------------------------------------------------

    vector<pair<OrderType, string>> types = {
        {HILBERT,   "HILBERT"},
        {MORTON,    "MORTON"},
        {SORT_X,    "X"},
        {SORT_Y,    "Y"},
        {SORT_SUM,  "SUM"},
        {SORT_DIFF, "DIFF"}
    };

    vector<int> hilbertOrder;

    for (auto [type, s] : types) {
        ll elapsed =
            chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now() - startTime
            ).count();

        if (elapsed >= TIME_LIMIT_MS)
            break;

        cerr << "\n[ORDER] building " << s
             << "  elapsed=" << elapsed << "ms\n";

        vector<int> ord = makeOrder(type);

        if (type == HILBERT)
            hilbertOrder = ord;

        processOrder(
            ord,
            s,
            startTime,
            TIME_LIMIT_MS
        );

        cerr << "[ORDER] finished " << s
             << " best=" << bestCost << '\n';
    }

    // --------------------------------------------------------
    // Additional random Hilbert perturbations.
    //
    // Rotate the coordinate system by changing x/y and signs.
    // This is cheap and gives different Hilbert traversals.
    // --------------------------------------------------------

    vector<int> transformedX(n + 1), transformedY(n + 1);

    for (int variant = 0; variant < 8; ++variant) {
        ll elapsed =
            chrono::duration_cast<chrono::milliseconds>(
                chrono::steady_clock::now() - startTime
            ).count();

        if (elapsed >= TIME_LIMIT_MS)
            break;

        for (int i = 1; i <= n; ++i) {
            int xx = X[i];
            int yy = Y[i];

            if (variant & 1)
                swap(xx, yy);

            if (variant & 2)
                xx = 1000000 - xx;

            if (variant & 4)
                yy = 1000000 - yy;

            transformedX[i] = xx;
            transformedY[i] = yy;
        }

        vector<NodeKey> keys;
        keys.reserve(n);

        const int SIDE = 1 << 20;

        for (int i = 1; i <= n; ++i) {
            keys.push_back({
                hilbertXY(
                    SIDE,
                    transformedX[i],
                    transformedY[i]
                ),
                i
            });
        }

        sort(
            keys.begin(),
            keys.end(),
            [](const NodeKey& a, const NodeKey& b) {
                if (a.key != b.key)
                    return a.key < b.key;
                return a.id < b.id;
            }
        );

        vector<int> ord(n);

        for (int i = 0; i < n; ++i)
            ord[i] = keys[i].id;

        cerr << "\n[ORDER] HILBERT variant "
             << variant << '\n';

        processOrder(
            ord,
            "HILBERT_VAR_" + to_string(variant),
            startTime,
            TIME_LIMIT_MS
        );
    }

    // --------------------------------------------------------
    // Final polishing.
    //
    // Use Hilbert order as neighborhood structure.
    // --------------------------------------------------------

    if (!hilbertOrder.empty()) {
        cerr << "\n[POLISH] start\n";

        polish(
            startTime,
            TIME_LIMIT_MS,
            hilbertOrder
        );
    }

    // --------------------------------------------------------
    // Safety fallback.
    // --------------------------------------------------------

    if (bestAns.empty()) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 1);

        bestAns.assign(
            ord.begin(),
            ord.begin() + m
        );

        bestCost = calcCost(bestAns);
    }

    // --------------------------------------------------------
    // Validate.
    // --------------------------------------------------------

    vector<char> used(n + 1, 0);

    bool valid = ((int)bestAns.size() == m);

    for (int id : bestAns) {
        if (id < 1 || id > n || used[id]) {
            valid = false;
            break;
        }

        used[id] = 1;
    }

    if (!valid) {
        cerr << "[ERROR] invalid answer, using fallback\n";

        bestAns.clear();

        FOR(i, 1, m)
            bestAns.push_back(i);

        bestCost = calcCost(bestAns);
    }

    // --------------------------------------------------------
    // Final information.
    // --------------------------------------------------------

    ll elapsed =
        chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now() - startTime
        ).count();

    cerr << "\n========================================\n";
    cerr << "FINAL\n";
    cerr << "cost = " << bestCost << '\n';
    cerr << "time = " << elapsed << " ms\n";
    cerr << "========================================\n";

    for (int i = 0; i < m; ++i) {
        if (i)
            cout << ' ';

        cout << bestAns[i];
    }

    cout << '\n';

    return 0;
}