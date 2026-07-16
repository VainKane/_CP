/*
 *  VMTRIP – Dời Đô xứ Dừa
 *  ----------------------
 *  N ≤ 1e5, M ≤ 3e5, K = |path| ≤ N
 *  Thuật toán  : BFS + binary‑lifting O((N+M) log N)
 *  Bộ nhớ      : O(N log N)
 *
 *  © 2025, viết theo phong cách “macro + hàm tách khối” đúng yêu cầu user :)
 *  // user: hay đấy :)
 */
#include <bits/stdc++.h>
using namespace std;

/* ==== hằng & kiểu dữ liệu ==== */
const int MAXN = 100000 + 5;
const int LOG   = 17;                 // 2^17 > 1e5
const int INF_RANK = 200000;          // > K luôn đủ an toàn

struct Pair { int rk, val; };         // rk nhỏ hơn -> ưu tiên
inline Pair best(const Pair &a, const Pair &b) {
    if (a.rk != b.rk) return (a.rk < b.rk ? a : b);
    return (a.val < b.val ? a : b);
}

/* ==== biến toàn cục (được phép theo “phong cách riêng”) ==== */
int n, m, S, T;
vector<int> adj[MAXN];

int distS[MAXN];
vector<int> layer[MAXN];              // các đỉnh theo độ sâu

int par[MAXN];
int up[MAXN][LOG + 1];
Pair info[MAXN][LOG + 1];             // (rank, value) nhỏ nhất trên đoạn 2^k

int rankPos[MAXN];                    // rankPos[pos] = thứ hạng của vị trí pos
int K;                                // chiều dài đường đi ngắn nhất

/* ==== BFS tính khoảng cách S → mọi đỉnh ==== */
void bfs_dist() {
    fill(distS, distS + n + 1, -1);
    queue<int> q; q.push(S); distS[S] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        layer[distS[u]].push_back(u);

        for (int v : adj[u])
            if (distS[v] == -1) {
                distS[v] = distS[u] + 1;
                q.push(v);
            }
    }
}

/* ==== so sánh hai đường đi tới u và tới v (đều đã là “tốt nhất” riêng) ==== */
bool better(int u, int v) {           // true  ⇔  path(u) < path(v)
    if (v == 0) return true;          // 0 = “chưa gán”
    if (u == 0 || u == v) return false;

    Pair A{INF_RANK, INT_MAX}, B{INF_RANK, INT_MAX};
    int x = u, y = v;

    for (int k = LOG; k >= 0; --k)
        if (up[x][k] != up[y][k]) {
            A = best(A, info[x][k]);
            B = best(B, info[y][k]);
            x = up[x][k];
            y = up[y][k];
        }

    A = best(A, info[x][0]);
    B = best(B, info[y][0]);

    if (A.rk != B.rk) return A.rk < B.rk;
    return A.val < B.val;
}

/* ==== xây dựng cha + bảng tổ tiên theo lớp ==== */
void build_parents() {
    par[S] = 0;
    info[S][0] = { rankPos[1], S };
    for (int k = 1; k <= LOG; ++k) {
        up[S][k] = 0;
        info[S][k] = info[S][0];
    }

    for (int d = 1; d < K; ++d)                       // duyệt lớp 1 .. K-1
        for (int u : layer[d]) {
            int bestPar = 0;
            for (int v : adj[u])
                if (distS[v] == distS[u] - 1)
                    if (better(v, bestPar))
                        bestPar = v;

            par[u] = bestPar;
            up[u][0] = bestPar;
            info[u][0] = { rankPos[d + 1], u };

            for (int k = 1; k <= LOG; ++k) {
                up[u][k]   = up[ up[u][k - 1] ][k - 1];
                info[u][k] = best(info[u][k - 1], info[ up[u][k - 1] ][k - 1]);
            }
        }
}

/* ==== main ==== */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ---- đọc đồ thị ---- */
    if (!(cin >> n >> m >> S >> T)) return 0;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /* ---- BFS khoảng cách ---- */
    bfs_dist();
    if (distS[T] == -1) { cout << -1 << '\n'; return 0; }
    K = distS[T] + 1;

    /* ---- đọc hoán vị p (độ dài K) ---- */
    vector<int> p(K + 1);
    for (int i = 1; i <= K; ++i) cin >> p[i];
    for (int i = 1; i <= K; ++i) rankPos[p[i]] = i;          // rank càng nhỏ càng quan trọng

    /* ---- bảng tổ tiên & so sánh ---- */
    build_parents();

    /* ---- reconstruct đường đi ---- */
    vector<int> path;
    for (int cur = T; cur; cur = par[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());

    /* ---- in kết quả ---- */
    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');
    return 0;
}
