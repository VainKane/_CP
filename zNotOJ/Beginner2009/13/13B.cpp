#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int k;

int a[(int)1e6 + 10];
deque<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        q = deque<int>();

        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && a[q.back()] >= a[i])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        cout << a[q.front()] << ' ';

        for (int i = k; i < n; i++)
        {
            if (i - q.front() >= k)
            {
                q.pop_front();
            }
            while (!q.empty() && a[q.back()] >= a[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            cout << a[q.front()] << ' ';
        }

        cout << '\n';
    }

    return 0;
}