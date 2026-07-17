#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define TASKNAME "TASKNAMEGOESHERE"

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

template<typename T> bool mini(T &a, const T &b) {
     return a > b ? a = b, 1 : 0;
}

template<typename T> bool maxi(T &a, const T &b) {
     return a < b ? a = b, 1 : 0;
}

struct State
{
    vector<vector<int>> v;
    int n = 0, x, y;

    State(int _n = 0)
    {
        n = _n;
        v.assign(n, vector<int> (4, 0));
    }

    bool operator < (State const other) const
    {
        REP(i, n) REP(j, 4) if (v[i][j] != other.v[i][j]) return v[i][j] < other.v[i][j];
        return false;
    }

    bool operator == (State const other) const
    {
        if (x != other.x || y != other.y) return false;
        REP(i, n) REP(j, 4) if (v[i][j] != other.v[i][j]) return false;
        return true;
    }

    void Print()
    {
        cout << '\n';
        REP(i, n)
        {
            REP(j, 4) cout << v[i][j] << ' ';
            cout << '\n';
        }
        cout << "pos: " << x << ' ' << y << '\n';
    }
};

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1};

int n;
State b;

map<State, int> mp;
State init;

bool Inside(int x, int y)
{
    return  x >= 0 && x < n &&
            y >= 0 && y < 4;
}

void BFS()
{
    queue<State> q;
    q.push(b);

    mp[b] = -1;

    while (!q.empty())
    {
        auto st = q.front();
        int x = st.x, y = st.y;
        q.pop();

        if (st == init)
        {
            vector<pair<int, int>> pos1, pos2;
            while (true)
            {
                int dir = mp[st];
                if (dir == -1) break;

                int u = st.x + dx[dir];
                int v = st.y + dy[dir];

                pos1.push_back({st.x + 1, st.y + 1});
                pos2.push_back({u + 1, v + 1});
                swap(st.v[st.x][st.y], st.v[u][v]);
                st.x = u, st.y = v;
            }

            reverse(all(pos1)); reverse(all(pos2));

            cout << sz(pos1) << '\n';
            REP(i, sz(pos1))
            {
                cout << pos1[i].F << ' ' << pos1[i].S << ' ' << pos2[i].F << ' ' << pos2[i].S << '\n';
            }

            return;
        }

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (!Inside(u, v)) continue;

            swap(st.v[x][y], st.v[u][v]);
            st.x = u, st.y = v;

            if (!mp.count(st))
            {
                mp[st] = {(i + 2) % 4};
                q.push(st);
            }


            swap(st.v[x][y], st.v[u][v]);
            st.x = x, st.y = y;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    b = init = State(n);
    init.x = n - 1, init.y = 3;

    REP(i, n) REP(j, 4)
    {
        init.v[i][j] = i * 4 + j + 1;
        cin >> b.v[i][j];
        if (b.v[i][j] == 4 * n) b.x = i, b.y = j;
    }

    BFS();

    return 0;
}
