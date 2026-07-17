#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;

struct matrix
{
    long long x[3][3];

    matrix()
    {
        memset(x, 0, sizeof x);
    }
};

matrix Multi(matrix &a, matrix &b)
{
    matrix c;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                c.x[i][j] = ( (c.x[i][j] % mod) + ( ((a.x[i][k] % mod) * (b.x[k][j] % mod)) % mod ) ) % mod;
            }
        }
    }

    return c;
}

matrix Pow(matrix &a, long long b)
{
    matrix c;

    for (int i = 0; i <= 2; i++)
    {
        c.x[i][i] = 1;
    }

    while (b)
    {
        if (b % 2 == 1)
        {
            c = Multi(c, a);
        }

        b /= 2;
        a = Multi(a, a);
    }

    return c;
}
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    matrix t;
    t.x[0][0] = t.x[0][1] = t.x[0][2] = t.x[1][0] = t.x[2][1] = 1;
    matrix u;

    u.x[0][0] = 4;
    u.x[1][0] = 2;
    u.x[2][0] = 1;

    t = Pow(t, n - 3);
    matrix c = Multi(t, u);

//    for (int i = 0; i <= 2; i++)
//    {
//        for (int j = 0; j <= 2; j++)
//        {
//            cout << t.x[i][j] << ' ';
//        }
//
//        cout << '\n';
//    }

    int f[5];
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;

    if (n >= 4) cout << c.x[0][0];
    else cout << f[n];


    return 0;
}
