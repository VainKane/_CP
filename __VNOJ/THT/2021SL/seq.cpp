#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const oo = 1e5;

int k, p;
string n = "";

bool mark[N];
vector<int> pos = {-1};
vector<int> id[256];

string GetDigits(int x)
{
    string res = "";

    while (x)
    {
        res += '0' + x % 10;
        x /= 10;
    }

    reverse(all(res));
    return res;
}

void Init()
{
    int idx = 1;
    while (sz(n) <= oo) n += GetDigits(idx++);
    REP(i, oo) if (n[i] == '9') pos.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();

    int t; cin >> t;
    while (t--)
    {
        cin >> k >> p;

        memset(mark, 0, sizeof mark);
        int idx = 0;

        while (k)
        {
            FOR(i, '0', '8') id[i].clear();
            FOR(i, pos[idx] + 1, pos[idx + 1] - 1) id[n[i]].push_back(i);
            FOR(i, '0', '8')
            {
                for (auto &j : id[i])
                {
                    mark[j] = true;
                    if (--k == 0) break;
                }

                if (k == 0) break;
            }

            idx++;
        }

        int cnt = 0;
        REP(i, oo)
        {
            cnt += !mark[i];
            if (cnt == p)
            {
                cout << n[i] << '\n';
                break;
            }
        }
    }

    return 0;
}