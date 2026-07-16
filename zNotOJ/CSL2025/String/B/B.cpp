#include <bits/stdc++.h>

using namespace std;

string str;
int n;

int lord[30];

long long t = 0;

int cnt[30];

int res;

int main()
{
    getline(cin, str);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char key;
        int value;

        cin >> key;
        cin >> value;

        lord[key - 'a'] = value;
    }

    for (char chr : str)
    {
        cnt[chr - 'a']++;
    }

    res = str.length();

    for (int i = 0; i < 30; i++)
    {
        int x = lord[i];
        int chuKiDu;
        int chuKiThieu;


        if (x > 0)
        {
            chuKiDu = (cnt[i] / (x - 1)) * (long long)x;
            chuKiThieu = cnt[i] % (x - 1) + 1;
//            cout << "x = " << x;
//            cout << " cnt = " << cnt[i] << '\n';
//            cout << chuKiDu << ' ' << chuKiThieu << '\n';

            res += chuKiDu;

            if (cnt[i] % (x - 1) != 0)
            {
                res += chuKiThieu;
            }

            res -= cnt[i];
        }
    }

    cout << res;

    return 0;
}
