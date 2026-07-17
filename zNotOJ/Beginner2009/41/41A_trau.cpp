#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

int n, m, k;
int p[N];              // quốc gia của từng khu vực
long long w[N];        // nhu cầu đá của từng quốc gia
long long collected[N]; // số đá đã thu được cho từng quốc gia
int res[N];            // ngày hoàn thành thu thập

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        collected[i] = 0;
        res[i] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    Init();

    cin >> k;

    for (int day = 1; day <= k; day++)
    {
        int l, r, c;
        cin >> l >> r >> c;

        if (l <= r)
        {
            for (int i = l; i <= r; i++)
            {
                int id = p[i];
                if (res[id] != -1) continue;

                collected[id] += c;

                if (collected[id] >= w[id])
                    res[id] = day;
            }
        }
        else
        {
            for (int i = l; i <= m; i++)
            {
                int id = p[i];
                if (res[id] != -1) continue;

                collected[id] += c;

                if (collected[id] >= w[id])
                    res[id] = day;
            }

            for (int i = 1; i <= r; i++)
            {
                int id = p[i];
                if (res[id] != -1) continue;

                collected[id] += c;

                if (collected[id] >= w[id])
                    res[id] = day;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';

    return 0;
}
