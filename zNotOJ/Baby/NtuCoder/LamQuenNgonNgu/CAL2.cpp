#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;

int main()
{
    cin >> a >> b >> c;

    cout << (long long)a * ((long long)b + c) + (long long)b * ((long long)a + c);
}