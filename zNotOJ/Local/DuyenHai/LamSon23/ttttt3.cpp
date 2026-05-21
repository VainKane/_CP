#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define all(v) v.begin(), v.end()
#define name "ttttt3"

int const MOD = 1e9 + 7;

int q, d;
int carry[15];

string ToString(int x)
{
    string res = "";
    
    while (x)
    {
        res += x % 10 + '0';
        x /= 10;
    }
    
    reverse(all(res));
    return res;
}

long long Add(string a, string b)
{
    memset(carry, 0, sizeof carry);
    reverse(all(a));
    reverse(all(b));

    if (a.size() > b.size()) swap(a, b);

    vector<int> digits;

    FOR(i, 0, 12)
    {
        int tmp = carry[i];
        if (i < a.size()) tmp += a[i] - '0';
        if (i < b.size()) tmp += b[i] - '0';

        digits.push_back(tmp % 10);
        carry[i + d] += tmp / 10;
    }

    long long res = 0;
    reverse(all(digits));
    for (auto d : digits) res = res * 10 + d;

    return res;
}

void AddMod(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> q >> d;
    while (q--)
    {
        int s; cin >> s;
        
        int res = 0;
        FOR(i, 0, s) FOR(j, i, s)
        {
            string a = ToString(i);
            string b = ToString(j);

            // if (Add(a, b) == s) cout << a << ' ' << b << '\n';
            AddMod(res, Add(a, b) == s);
        }

        cout << res;
    }

    return 0;
}