#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

void Solve(pair<int, int> a[], int prefix[], int n)
{
    pair<int, int> pre = a[0];
    int maxLength = 0;
    int maxIndex;
    int minIndex;

    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        i--;
        minIndex = maxIndex = pre.first;

        while (a[i].second == pre.second)
        {
            maxIndex = max(maxIndex, a[i].first);
            minIndex = min(minIndex, a[i].first);

            if  (maxLength < maxIndex - minIndex + 1)
            {
                maxLength = maxIndex - minIndex + 1;
                sum = prefix[maxIndex] - prefix[minIndex - 1];
            }
            else if (maxLength == maxIndex - minIndex + 1)
            {
                sum = max(sum, prefix[maxIndex] - prefix[minIndex - 1]);
            }

            i++;
        }

        pre = a[i];
    }

    cout << maxLength << ' ' << sum;
}

int n;

pair<int, int> a[(int)1e6 + 10];
int prefix[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("EXLIST.INP", "r", stdin);
    freopen("EXLIST.OUT", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        a[i] = {i, value};
        prefix[0] = a[0].second;

        if (i > 0)
        {
            prefix[i] = prefix[i - 1] + value;
        }
    }

    sort(a, a + n, cmp);

    Solve(a, prefix, n);

    return 0;
}
