#include <bits/stdc++.h>

using namespace std;

long long Count(int n)
{
    long long twos = 0;
    long long fives = 0;

    for (int i = 2; i <= n; i += 2)
    {
        int j = i;
        while (j % 2 == 0)
        {
            twos++;
            j /= 2;
        }
    }

    for (int i = 5; i <= n; i += 5)
    {
        int j = i;
        while (j % 5 == 0)
        {
            fives++;
            j /= 5;
        }
    }

    return min(twos, fives);
}

int cnt[29];
string s;

long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for (char chr : s)
    {
        cnt[chr - 'a']++;
    }

    res = Count(s.length());

    for (int i = 0; i < 29; i++)
    {
        res -= Count(cnt[i]);
    }

    cout << res;
    
    return 0;
}