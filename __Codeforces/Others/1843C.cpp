#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        long long sum = 0;

        while (n)
        {
            sum += n;
            n /= 2;
        }

        cout << sum << '\n';
    }

    return 0;
}