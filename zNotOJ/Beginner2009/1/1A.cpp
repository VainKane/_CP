#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second) return true;
    else if (a.second == b.second) return (a.first < b.first);
    else return false;
}

bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second <b.second;
    return false;
}

int n;
pair <int, int> a[109];
int cnt = 0;

pair<int, int> res[4959];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        a[i].first = i;
        a[i].second = val;
    }

    sort(a, a + n, cmp);

    int i = 0;
    int j = 1;

    while (i < n)
    {
        while (a[j].second == a[i].second)
        {
            for (int k = i; k < j; k++)
            {
                res[cnt].first = a[k].first + 1;
                res[cnt].second = a[j].first + 1;
                cnt++;
            }
            j++;
        }

        i = j;
        j += 1;
    }

    cout << cnt << '\n';

    sort(res, res + cnt, cmp1);
    
    for (int i = 0; i < cnt; i++)
    {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}