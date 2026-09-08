#include <bits/stdc++.h>

using namespace std;

long long x;
set<long long> t;

long long sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x;

    string s = bitset<64> (x).to_string();

    for (int l = 1; l <= s.length(); l++)
    {
        for (int i = 0; i <= s.length() - 1; i++)
        {
            bitset<64> b(s.substr(i, l));
            t.insert(b.to_ullong());
        }
    }

    for (auto val : t) sum += val;

    cout << sum;

    return 0;
}