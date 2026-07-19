#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int q;

int a[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        string res = "";
        
        int iq = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] <= iq)
            {
                res += '1';
            }
            else
            {
                if (iq < q)
                {
                    res += '1';
                    iq++;
                }
                else if (iq == q) res += '0';
            }
        }

        for (int i = res.length() - 1; i >= 0; i--) cout << res[i];
        cout << '\n';
    }

    return 0;
}