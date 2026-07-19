#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int a[(int)2e5 + 10];
bool cnt[(int)2e5 + 10];
bool c[(int)2e5 + 10];

vector<int> diff;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        memset(cnt, 0, sizeof cnt);
        memset(c, 0, sizeof c);
        diff.clear();

        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            cnt[a[i]] = true;
        }


        for (int i = 1; i <= n; i++)
        {
            if (!cnt[i])
            {
                diff.push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!c[a[i]])
            {
                cout << a[i] << ' ';
                c[a[i]] = true;
            }
            else
            {
                cout << diff.back() << ' ';
                diff.pop_back();
            }
        }

        cout << '\n';
    }

    return 0;
}