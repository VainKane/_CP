#include <bits/stdc++.h>

using namespace std;

bool IsEqual(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first && a.second == b.second) return true;
    return false;
}

bool Check(multiset<int> t)
{
    int cnt = 0;

    for (auto val : t)
    {
        if (t.count(val) >= 2) cnt++;
    }

    return cnt >= 3;
}

pair<int, int> p[6];

multiset<int> t;
set<pair<int, int>> visisted;   

int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++)
    {
        int x, y;
        cin >> x >> y;

        p[i].first = min(x, y);
        p[i].second = max(x, y);
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (IsEqual(p[i], p[j]))
            {
                if (visisted.count(make_pair(i, j)) == 0)
                {
                    t.insert(p[i].first);
                    t.insert(p[i].second);

                    visisted.insert(make_pair(i, j));

                    cnt++;
                } 
            }
        }
    }

    cout << cnt;

    if (Check(t) || cnt == 3)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
    return 0;
}