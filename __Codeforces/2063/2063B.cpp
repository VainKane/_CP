#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

int n;
int t;
int l;
int r;

long long sum1;
long long sum2;

vector<int> a;
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> l >> r;
        l--; r--;
        sum1 = sum2 = 0;

        a.clear();
        b.clear();

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;

            if (i <= r) a.push_back(val);
            if (i >= l) b.push_back(val);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i <= r - l; i++)
        { 
            sum1 += 1LL * a[i];
        }

        for (int i = 0; i <= r - l; i++) 
        {
            sum2 += 1LL * b[i];
        }
        
        cout << min(sum1, sum2) << '\n';
    }

    return 0;
}