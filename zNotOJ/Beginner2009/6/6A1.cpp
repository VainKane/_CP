#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];

int x[20];

vector<int> res;

void Sum(int k)
{
    int sum = 0;

    for (int i = 1; i <= k; i++)
    {
        sum += a[x[i]];
    }

    res.push_back(sum);
}


void Try(int i, int k)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;

        if (i == k)
        {
            Sum(k);
        }
        else
        {
            Try(i + 1, k);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    x[0] = 0;
    res.push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        Try(1, i);
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() << '\n';
    for (auto val : res) cout << val << ' ';

    return 0;
}