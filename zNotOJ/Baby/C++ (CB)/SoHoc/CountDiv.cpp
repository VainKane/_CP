#include <bits/stdc++.h>

int CountCM(int l, int r, int a, int b);


int times;

int l;
int r;
int a;
int b;

int main()
{
    freopen("CountDiv.inp", "r", stdin);
    freopen("CountDiv.out", "w", stdout);

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> l >> r >> a >> b;
        std::cout << CountCM(l, r, a, b) << '\n';
    }
}

int CountCM(int l, int r, int a, int b)
{
    int count = 0;

    for (int i = a; i <= r; i += a)
    {
        if (i >= l)
        {
            count += 1;
        }
    }

    for (int i = b; i <= r; i += b)
    {
        if (i >= l)
        {
            if (i % a != 0)
            {
                count += 1;
            }
        }
    }

    return count;
}
