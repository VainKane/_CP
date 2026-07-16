#include <bits/stdc++.h>

using namespace std;

int t;

int cnt[3];

int main()
{
    cin >> t;

    while (t--)
    {
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < 9; i++)
        {
            char chr;
            cin >> chr;

            if (chr != '?') cnt[chr - 'A']++;
        }

        for (int i = 0; i < 3; i++)
        {
            if (cnt[i] == 2) cout << (char)(i + 'A') << '\n';
        }
    }

    return 0;
}