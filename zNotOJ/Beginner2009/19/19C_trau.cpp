#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct Pos
{
    int c1, c2, d;
};

int const X = 1e6 + 1;
int const N = 6 * X + 10;

int a[4], b[4], c[4];

int s = 0;
int v[4];

int d[N];

map<pair<int, int>, int> mp;

int GetVal(int v[])
{
    int res = v[2];
    FOR(i, 1, 3)
    {
        if (!v[i]) return res;
        res += X;
        if (v[i] == a[i]) return res;
        res += X;
    }

    return N - 2;
}

void Print(int v[])
{
    int tmp[4];
    FOR(i, 1, 3) tmp[i] = v[i];

    sort(tmp + 1, tmp + 4);
    FOR(i, 1, 3) if (tmp[i] != c[i]) return;

    // cout << d[GetVal(v)];
    cout << mp[{v[1], v[2]}];
    cerr << mp[{v[1], v[2]}];
    exit(0);
}

void BFS()
{
    queue<Pos> q;
    q.push({b[1], b[2], 0});

    int tmp[4];

    while (!q.empty())
    {
        tmp[1] = q.front().c1;
        tmp[2] = q.front().c2;
        tmp[3] = s - tmp[1] - tmp[2];

        int prev = GetVal(tmp);
        Print(tmp);

        q.pop();

        FOR(i, 1, 3) FOR(j, 1, 3) if (i != j)
        {
            int x = min(tmp[i], a[j] - tmp[j]);
            
            v[i] = tmp[i] - x;
            v[j] = tmp[j] + x;
            v[6 - i - j] = s - v[i] - v[j];
        
            int id = GetVal(v);
            // if (d[id] != -1) continue;
            if (mp.count({v[1], v[2]})) continue;

            q.push(Pos{v[1], v[2]});
            // d[id] = d[prev] + 1;
            mp[{v[1], v[2]}] = mp[{tmp[1], tmp[2]}] + 1;  
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 1, 3) cin >> a[i];
    FOR(i, 1, 3) cin >> b[i], s += b[i];
    FOR(i, 1, 3) cin >> c[i];

    memset(d, -1, sizeof d);
    d[N - 2] = 0;

    mp[{b[1], b[2]}] = 0;
    sort(c + 1, c + 4);

    BFS();
    cout << -1;
    cerr << -1 << '\n';

    return 0;
}