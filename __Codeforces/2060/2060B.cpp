#include <bits/stdc++.h>

using namespace std;

struct Cow
{
    int cards[2009];
};

bool cmp(Cow a, Cow b)
{
    return a.cards[0] < b.cards[0];
}

bool Check(Cow cows[], int n, int m)
{
    int pre = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (cows[j].cards[i] <= cows[j - 1].cards[i] || cows[j].cards[i] <= pre)
            {
                return false;
            }
        }

        pre = cows[n - 1].cards[i];
    }

    return true;
}

int t;

int n;
int m;

Cow cows[2009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cows[i].cards[j];
            }

            cows[i].cards[m] = i;
            sort(cows[i].cards, cows[i].cards + m);
        }

        sort(cows, cows + n, cmp);

        if (Check(cows, n, m))
        {
            for (int i = 0; i < n; i++) cout << cows[i].cards[m] + 1 << ' ';
        } else cout << -1;

        cout << '\n';
    }

    return 0;
}