#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

using namespace std;

struct Cow
{
    int x;
    int h;
};

bool cmp(Cow a, Cow b)
{
    return (a.x < b.x);
}

int n;
int d;

Cow cows[(int)1e5 + 10];

int cnt = 0;

int l[(int)1e6 + 10];
int r[(int)1e6 + 10];

deque <int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> cows[i].x >> cows[i].h;
    sort(cows, cows + n, cmp);

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && cows[q.front()].x < cows[i].x - d) q.pop_front();
        while (!q.empty() && cows[i].h >= cows[q.back()].h) q.pop_back();

        q.push_back(i);
        l[i] = cows[q.front()].h;
    }

    q = deque<int> (0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!q.empty() && cows[i].x < cows[q.front()].x - d) q.pop_front();
        while (!q.empty() && cows[i].h >= cows[q.back()].h) q.pop_back();

        q.push_back(i);
        r[i] = cows[q.front()].h;
    }

    for (int i = 0; i < n; i++)
    {
        if (l[i] >= 2 * cows[i].h && r[i] >= 2 * cows[i].h) cnt++;
    }

    cout << cnt;

    return 0;
}
