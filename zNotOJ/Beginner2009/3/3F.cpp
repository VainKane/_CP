#include <bits/stdc++.h>

using namespace std;

bool IsEqual(pair<int, int> a, pair<int, int> b)
{
    return (a.first == b.first && a.second == b.second);
}

bool Check(pair<int, int> p[])
{
    for (int i = 0; i < 3; i += 2)
    {
        if (!IsEqual(p[i], p[i + 1])) return false;
    }

    if (p[1].second != p[5].first) return false;
    if (p[1].first != p[2].first) return false;

    return true;
}

pair<int, int> p[6];

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

    sort(p, p + 6);

    if (Check(p)) cout << "YES";
    else cout << "NO";

    return 0;
}