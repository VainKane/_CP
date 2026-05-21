#include <bits/stdc++.h>

using namespace std;

string str;
int cnt[30];
string res = "";
int count1 = 0;

const int mod = 1e9 + 7;

int PowMod(long long a, int b)
{
    long long res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= a % mod;
            res %= mod;
        }

        b /= 2;
        a *= a % mod;
        a %= mod;
    }

    return res;
}

void Print()
{
    cout << res << '\n';
}

void Try(int i)
{
    for (int j = 0; j <= 26; j++)
    {
        if (cnt[j] > 0)
        {
            res += (char)(j + 'a');
            cnt[j]--;

            if (i == str.length() - 1)
            {
                count1++;
            }
            else
            {
                Try(i + 1);
            }

            cnt[j]++;
            res.erase(res.length() - 1, 1);
        }
    }
}

int Solve(string str)
{
    long long res = 1;

    int f[(int)1e5 + 10];

    f[0] = 1;

    for (int i = 1; i <= str.length(); i++)
    {
        f[i] = ( (long long) (f[i - 1] % mod) * (i % mod) ) % mod;
    }

    res = f[str.length()];


    for (int i = 0; i <= 26; i++)
    {
        if (cnt[i] > 0)
        {
            int a = f[cnt[i]];

            a = PowMod(a, mod - 2);

            res *= (long long)a;
            res %= mod;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;

    for (char chr : str)
    {
        cnt[chr - 'a']++;
    }

//    Try(0);

    cout << Solve(str);


    return 0;
}
