#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;
int const maxLength = 1e2;

int n;
string s;

bool visisted[N];
int trace[N];
int digit[N];

int cnt = 0;

void Print(int u, int v)
{
    deque<int> res;
    while (u)
    {
        res.push_front(digit[u]);
        u = trace[u];
    }
    res.push_back(v);
    for (auto val : res) cout << val;

    exit(0);
}
 

int BFS()
{
    queue<pair<int, int>> qu;

    for (auto d : s)
    {
        if (d - '0' == 0) continue;

        if ((d - '0') % n == 0) return d - '0';
        qu.push({++cnt, d - '0'});
        digit[cnt] = d - '0';
    }

    while (!qu.empty())
    {
        int u = qu.front().first;
        int rem = qu.front().second;
        qu.pop();

        for (auto d : s)
        {
            int r = ( rem * 10 + (d - '0') ) % n;

            if (!visisted[r])
            {
                visisted[r] = true;
                
                qu.push({++cnt, r});
                digit[cnt] = d - '0';
                trace[cnt] = u;
            }

            if (r == 0)
            {
                Print(u, d - '0');
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("18E.inp", "r", stdin);
    // freopen("18E.out", "w", stdout);

    cin >> n;
    cin >> s;

    sort(s.begin(), s.end());

    cout << BFS();

    return 0;
}