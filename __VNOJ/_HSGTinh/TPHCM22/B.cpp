#include <bits/stdc++.h>

using namespace std;

#define name "B"

int const N = 2e5 + 5;
int const MOD = 1e3 + 7;

int n, q;

int bit[N];
int t[4 * N];
int lz[4 * N];

struct Matrix
{
    int x[3][3];
    Matrix() 
    {
        memset(x, 0, sizeof x);
    }
    static Matrix I()
    {
        Matrix res;
        for (int i = 1; i <= 2; i++) res.x[i][i] = 1;
        return res;
    }
};

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                res.x[i][j] = (res.x[i][j] + a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix Pow(Matrix a, long long b)
{
    Matrix res = Matrix::I();
    while (b)
    {
        if (b & 1)
        {
            res = Multi(res, a);
        }
        b >>= 1;
        a = Multi(a, a);
    }
    return res;
}

void Print(Matrix a)
{
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++) cout << a.x[i][j] << ' ';
        cout << '\n';
    }
}

void Push(int v, int l, int r)
{
    int mid = l + (r - l) / 2;

    if (lz[v])
    {
        t[2 * v] += lz[v] * (mid - l + 1);
        t[2 * v + 1] += lz[v] * (r - mid);
        lz[2 * v] += lz[v];
        lz[2 * v + 1] += lz[v];
    
        lz[v] = 0;
    }
}

void Update(int v, int l, int r, int left, int right, int val)
{
    if (l > right || r < left) return;
    if (left <= l && right >= r)
    {
        t[v] += val * (r - l + 1);
        lz[v] += val;
        return;
    }

    Push(v, l, r);
    int mid = l + (r - l) / 2;

    Update(2 * v, l, mid, left, right, val);
    Update(2 * v + 1, mid + 1, r, left, right, val);

    t[v] = t[2 * v] + t[2 * v + 1];
}

int GetSum(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return 0;
    if (left <= l && right >= r) return t[v];

    Push(v, l, r);
    int mid = l + (r - l) / 2;

    int s1 = GetSum(2 * v, l, mid, left, right);
    int s2 = GetSum(2 * v + 1, mid + 1, r, left, right);

    return s1 + s2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    Matrix T;
    Matrix B;
    T.x[1][2] = T.x[2][1] = T.x[2][2] = 1;
    B.x[1][1] = B.x[2][1] = 1;     
        
    cin >> n >> q;
    while (q--)
    {
        int type;
        int l, r;
        cin >> type >> l >> r;

        if (type == 1)
        {
            long long k;
            cin >> k;
            Update(1, 1, n, l, r, Multi(Pow(T, k - 1), B).x[1][1]);

            // cout << "After Query1:\n";
            // for (int i = 1; i <= n; i++) cout << GetSum(1, 1, n, i, i) << ' ';
            // cout << '\n';
        }
        else
        {
            // cout << "Query2: " << l << ' ' << r << '\n';
            cout << GetSum(1, 1, n, l, r) << '\n';
        }
    }

    // cout << "t[3] [4..5] " << t[3] << ' ' << GetSum(1, 1, n, 4, 4) << ' ' << GetSum(1, 1, n, 5, 5);

    return 0;
}