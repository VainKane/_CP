#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "CULTURE"

int const N = 1e5 + 5;

int n;
int res = 0;

int pos[N];
int bit[N];

map<string, int> a;

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int GetSum(int idx)
{
    int res = 0;
    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        a[s] = i;
    }    

    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        pos[i] = a[s];
    }

    // for (int i = 1; i <= n; i++) cout << pos[i] << ' ';

    for (int i = n; i >= 1; i--)
    {
        res += GetSum(pos[i] - 1);
        Update(pos[i], 1);
    }   

    cout << res;

    return 0;
}