#include <bits/stdc++.h>

using namespace std;

bool Check(vector<int> a, int cnt[], int n)
{
    if (n % 2 == 1) return false;

    int c = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (c == n / 2) return false;

        if (cnt[a[i]] < 2)
        {
            return false;
        }

        if (cnt[a[i]] > 2)
        {
            int tmp = a[i];

            c++;

            a.erase(a.begin(), a.begin() + 2);
            cnt[a[i]] -= 2;
            
            int j = 0;

            while (a[j] == tmp && j < a.size())
            {
                a[j]++;
                cnt[a[j]]++;
                j++;
            }

            i--;
        }
        else
        {
            c++;

            cnt[a[i]] -= 2;
            a.erase(a.begin(), a.begin() + 2);

            i--;
        }
    }

    return (c == n / 2);
}

int t;
int n;

vector<int> a;
int cnt[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
     
        a.clear();
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            a.push_back(val);
            cnt[a[i]]++;
        }

        sort(a.begin(), a.end());

        if (Check(a, cnt, n)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}