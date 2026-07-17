#include <bits/stdc++.h>

using namespace std;

struct Dragon
{
    int x;
    int y;
};

bool cmp(Dragon a, Dragon b)
{
    if (a.x < b.x)
    {
        return true;
    }
    else if (a.x == b.x)
    {
        if (a.y >= b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Check(Dragon dragons[], int n, long long s)
{
    for (int i = 0; i < n; i++)
    {
        if (s <= dragons[i].x)
        {
            return false;
        }
        s += 1LL * dragons[i].y;
    }

    return true;
}

int n;
long long s;

Dragon dragons[(int)1e3 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> dragons[i].x >> dragons[i].y;
    }

    sort(dragons, dragons + n, cmp);

    if (Check(dragons, n, s)) cout << "YES";
    else cout << "NO";

    return 0;
}