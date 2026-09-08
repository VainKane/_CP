#include <bits/stdc++.h>

using namespace std;

int const M = 1e6 + 10;
string s;

int cntLower[M];
int cntUpper[M];
int cntNum[M];

long long res = 0;

bool Check(int l, int r)
{
    bool c1 = (cntLower[r] - cntLower[l - 1] > 0);
    bool c2 = (cntUpper[r] - cntUpper[l - 1] > 0);
    bool c3 = (cntNum[r] - cntNum[l - 1] > 0);

    return (c1 && c2 && c3 && (r - l >= 7));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        cntLower[i] = cntLower[i - 1];
        cntUpper[i] = cntUpper[i - 1];
        cntNum[i] = cntNum[i - 1];

        if (islower(s[i])) cntLower[i]++;
        if (isupper(s[i])) cntUpper[i]++;
        if (s[i] >= '0' && s[i] <= '9') cntNum[i]++;
    }

    int l = 0; 
    int r = s.length() - 1;

    for (int i = 0; i <= s.length(); i++)
    {
        int l = i + 7;
        int r = s.length() - 1;

        int k = s.length();

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (Check(i, mid))
            {
                k = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        res += s.length() - k;
    }

    cout << res;

    return 0;
}