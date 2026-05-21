#include <bits/stdc++.h>

using namespace std;

struct Truck
{
    int s;
    int f;
    int c;
    int r;
};

bool Check(Truck trucks[], long long v, int d[], int m)
{
    for (int i = 0; i < m; i++)
    {
        long long f = v;
        int r = trucks[i].r;

        for (int j = trucks[i].s - 1; j < trucks[i].f - 1; j++)
        {
            long long fNeed = 1LL * d[j] * trucks[i].c;
            if (fNeed > v) return false;

            if (f >= fNeed)
            {
                f -= fNeed;
            }
            else
            {
                f = v;
                r--;
                if (r < 0) return false;
                f -= fNeed;
            }
        }
    }

    return true;
}

int n;
int m;

int a[(int)1e3 + 10];
Truck trucks[250009];
int d[(int)1e3 + 10];

long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        d[i - 1] = a[i] - a[i - 1];
    }


    for (int i = 0; i < m; i++)
    {
        cin >> trucks[i].s >> trucks[i].f >> trucks[i].c >> trucks[i].r;
    }

    long long l = 1;
    long long r = 1e18;
    long long mid;

    while (l <= r)
    {
        mid = ( l + r ) / 2;

        if (Check(trucks, mid, d, m))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}
