#include <bits/stdc++.h>

using namespace std;

deque<int> q;
int n;
int k;
int a[(int)1e6 + 10];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && a[q.back()] <= a[i])
        {
            q.pop_back();
        }

        q.push_back(i);
    }

    cout << a[q.front()] << ' ';

    for (int i = k; i < n; i++)
    {
        if (q.front() + k <= i)
        {
            q.pop_front();
        }

        while (!q.empty() && a[q.back()] <= a[i])
        {
            q.pop_back();
        }

        q.push_back(i);

        cout << a[q.front()] << ' ';
    }

    return 0;
}