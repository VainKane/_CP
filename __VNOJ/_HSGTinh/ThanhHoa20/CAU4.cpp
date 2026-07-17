#include <bits/stdc++.h>

using namespace std;

#define name "CAU4"

int const N = 1e6 + 5;

string s;

int cnt1[N];
int cnt2[N];

long long res = 0;

bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    s = " " + s;
    int n = s.size() - 1;

    for (int i = 1; i <= n; i++) 
    {
        cnt1[i] = cnt1[i - 1];
        cnt2[i] = cnt2[i - 1];

        if (isVowel(s[i])) cnt1[i]++;
        else cnt2[i]++;
    }

    for (int i = 1; i < n; i++)
    {
        if (isVowel(s[i])) res += cnt2[n] - cnt2[i];
        else res += cnt1[n] - cnt1[i];
    }

    cout << res;

    return 0;
}