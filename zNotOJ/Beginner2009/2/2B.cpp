#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    return false;
}

int n;
pair <int, int> p[109];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + n, cmp);

    res = p[0].first + p[0].second;

    for (int i = 1; i < n; i++)
    {
        if (p[i].first >= res) 
        {
            res = p[i].first + p[i].second;
        }
        else
        {
            res = res + p[i].second;
        }
    }

    cout << res;

    return 0;
}