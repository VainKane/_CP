#include <bits/stdc++.h>

using namespace std;

#define name "QUA"

int const N = 3e5 + 5;

int Sum[N];
int n;

vector<int> res;

void Sieve()
{
    for (int i = 1; i * i <= 3e5; i++)
    {
        for (int j = i * i; j <= 3e5; j += i)
        {
            Sum[j] += i;
            if (i * i != j) Sum[j] += j / i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Sieve();
    
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int x;
        cin >> x;
        if (Sum[x] - x == x)
        {
            res.push_back(x);
        }
    }

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}