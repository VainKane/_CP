#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define MK(i) (1ll << (i))

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 20;

int n;
char s[N], t[N];
char res[N];
bool used[256];

vector<int> v;

bool Check()
{
    FOR(i, 1, n - 1)
    {
        if (t[i] == t[i - 1]) return false;
        if (t[i - 1] == t[i + 1]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> s[i], used[s[i]] = true;
    FOR(i, 'a', 'z') if (!used[i]) 
    {
        if (sz(v) == (n + 1) / 2 + 2) break;
        v.push_back(i);
    }

    int cnt = n + 1;

    REP(mask, MK(n)) if (__builtin_popcount(mask) <= (n + 1) / 2 + 2)
    {
        sort(all(v));
        do
        {
            REP(i, n) t[i] = s[i]; 
            int c = 0;
            for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
            {
                int i = __builtin_ctz(tmp & -tmp);
                t[i] = v[c++];
            }

            // REP(i, n) cout << t[i];
            // cout << '\n';

            if (Check())
            {   
                if (mini(cnt, __builtin_popcount(mask))) REP(i, n) res[i] = t[i];
                break;
            }
        }
        while (next_permutation(all(v)));
    }

    cout << cnt << '\n';
    // REP(i, n) cout << res[i];

    // for (auto &ch : v) cout << (char)ch;

    return 0;
}