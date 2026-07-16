#include <bits/stdc++.h>

using namespace std;

int t;

int n;
int c[1009];

int cnt[1009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n; 

        memset(cnt, 0, sizeof cnt);

        int a;
        int b;

        if (n % 2 == 0) a = b = n / 2;
        else 
        {
            a = n / 2 + 1;
            b = n / 2;
        }

        int res = 0;

        for (int i = 0; i < n; i++) 
        {
            cin >> c[i];
            cnt[c[i]]++;
        }
        
        while (b)
        {
            auto it = max_element(cnt, cnt + 1005);
            
            if (*it == 1)
            {
                b -= 1;
                *it = 0;
            }
            else if (*it - 1 <= b) 
            {
                b -= *it - 1;
                *it = -1;
            }
            else
            {
                b = 0;
                *it = -1;
            }
        }

        for (int i = 0; i < 1005; i++)
        {
            if (cnt[i] == -1) res += 1;
            else if (cnt[i] != 0) res += 2;
        }

        cout << res << '\n';
    }

    return 0;
}