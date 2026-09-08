#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)v.size())

multiset<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("H.inp", "r", stdin);
    freopen("H.ans", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        char type; cin >> type;
        if (type == '+') 
        {
            int x; cin >> x;
            st.insert(x);
        }
        else if (type == '-') 
        {
            int x; cin >> x;
            if (!st.count(x)) continue;
            st.erase(st.find(x));
        }
        else 
        {
            int k, l, r;
            cin >> k >> l >> r;

            vector<int> v;
            for (auto &x : st) if (x >= l && x <= r) v.push_back(x);
            cout << (sz(v) >= k ? v[k - 1] : 0) << '\n';
        }
    }
}