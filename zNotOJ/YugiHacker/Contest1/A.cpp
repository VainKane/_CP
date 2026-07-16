#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _ a = (a); i >= _a; i--)
#define sz(v) ((int)v.size())

int const N = 1e5 + 5;
int const oo = 1e9 + 1;

int n;
int a[N];

int r[N];
bool used[N];
int res[N];

void Init()
{
    stack<int> st;
    memset(used, false, sizeof used);
    memset(res, 0, sizeof res);

    a[n + 1] = oo;
    FOR(i, 1, n + 1)
    {
        while (!st.empty() && a[i] >= a[st.top()])
        {
            r[st.top()] = a[i] == a[st.top()] ? i : 0;
            st.pop();
        }
        st.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        Init();
        
        FOR(i, 1, n) if (!used[i])
        {
            vector<int> idxes;
            int j = i;

            while (j)
            {
                idxes.push_back(j);
                used[j] = true;
                j = r[j];
            }

            for (auto &idx : idxes) res[idx] = sz(idxes) - 1;
        }

        FOR(i, 1, n) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}