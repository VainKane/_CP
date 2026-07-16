#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (((x) >> (i)) & 1)
#define name "scrivener"

int const N = 1e6;
int const maxLog = 20;

struct Node
{
    char ch;
    int depth = 0;
};

Node node[N];

int pos[N];
int par[N];
int up[N][maxLog];
int cnt = 0;
int ind = 0;

int n;

void Type(char &ch)
{
    pos[ind] = ind;
    node[pos[ind]].ch = ch;
    par[ind] = pos[ind - 1];
    node[ind].depth = node[par[ind]].depth + 1;

    up[ind][0] = par[ind];
    for (int v = 1; (1 << v) <= n; v++)
    {
        up[ind][v] = up[up[ind][v - 1]][v - 1];
    }
}

void Undo(int &k)
{
    pos[ind] = pos[ind - 1 - k];
}

char Get(int &x, int ind)
{
    ind = pos[ind];
    int k = node[ind].depth - x;

    for (int i = 0; i <= maxLog; i++)
    {
        if (bit(i, k))
        {
            ind = up[ind][i];
        }
    }

    return node[ind].ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> n;
    for (int i = 1; i <= n; i++)
    {
        char type; cin >> type;

        up[i][0] = par[i];

        if (type == 'T') 
        {
            char x; cin >> x;

            ind++;
            Type(x);
        }
        else if (type == 'U') 
        {
            int k; cin >> k;

            ind++;
            Undo(k);
        }
        else
        {
            int k; cin >> k;
            cout << Get(k, ind);
        }
    }

    return 0;
}