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

int const N = 5e5 + 5;

int n, t;
bool mark[N];
int b[N];

bool rotateV[N];
pair<int, int> posV[N], posK[N];

void Rotate(int &x, int &y, int xCen, int yCen)
{
    if (x < xCen && y == yCen) x++, y++;
    else if (x == xCen && y > yCen) x++, y--;
    else if (x > xCen && y == yCen) x--, y--;
    else x--, y++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    FOR(i, 1, n) 
    {
        cin >> b[i];
        mark[b[i]] = true;
    }

    int xV = 0, yV = 0;
    int xK = 1, yK = 0;

    rotateV[1] = true;

    FOR(i, 1, t)
    {
        if (rotateV[i]) Rotate(xV, yV, xK, yK);
        else Rotate(xK, yK, xV, yV);
        rotateV[i + 1] = rotateV[i] ^ mark[i];

        posV[i] = {xV, yV};
        posK[i] = {xK, yK};
    }

    FOR(i, 1, n)
    {
        int j = b[i] + 1;
        int x = posV[j].F, y = posV[j].S;
        if (rotateV[j])
        {
            int rem = (t - j) % 4;
            FOR(haha, 1, rem) Rotate(x, y, posK[j].F, posK[j].S);
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}