#include <bits/stdc++.h>

using namespace std;

string a [] {"TAO", "CAM", "XOAI", "MIT", "NHAN", "VAI", "QUYT", "BUOI", "CHUOI", "NHO"};

int n;
int k;
vector<string> f;
int x[20];

void Print()
{
    for (int i = 1; i <= k; i++)
    {
        cout << f[x[i] - 1] << ' ';
    }

    cout << '\n';
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;

        if (i == k)
        {
            Print();
        }
        else 
        {
            Try(i + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        f.push_back(a[i]);
    }

    sort(f.begin(), f.end());

    Try(1);

    return 0;
}