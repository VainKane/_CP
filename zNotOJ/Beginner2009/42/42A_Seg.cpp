#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x[4];

    Node()
    {
        memset(x, 0, sizeof x);
    }

    static Node Empty()
    {
        Node res;
        return res;
    }
};

int const N = 1e5 + 5;

int n, k;
int a[N];

Node t[4 * N];
long long res = 0;

void Merge(Node &v, Node a, Node b)
{
    int l = 1;
    int r = 1;

    for (int i = 1; i <= 3; i++)
    {
        if (a.x[l] > b.x[r])
        {
            v.x[i] = a.x[l];
            l++;
        }
        else
        {
            v.x[i] = b.x[r];
            r++;
        }
    }
}

void Build(int v, int l, int r)
{
    if (l == r)
    {
        t[v].x[1] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;

    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);
    
    Merge(t[v], t[2 * v], t[2 * v + 1]);
}

Node GetMax(int v, int l, int r, int left, int right)
{
    if (l > right || r < left) return Node::Empty();
    if (left <= l && right >= r) return t[v];

    int mid = l + (r - l) / 2;
    Node max1 = GetMax(2 * v, l, mid, left, right);
    Node max2 = GetMax(2 * v + 1, mid + 1, r, left, right);

    Node res = Node::Empty();
    Merge(res, max1, max2);
    return res;
}

long long GetVal(Node a)
{
    long long res = 1;
    for (int i = 1; i <= 3; i++) res *= a.x[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Build(1, 1, n);
    
    for (int i = min(k + 1, n); i <= n; i++)
    {
        res = max(res, GetVal(GetMax(1, 1, n, i - k, max(i, 1))));
    }

    cout << res;

    // for (int i = 1; i <= 3; i++) cout << t[1].x[i] << ' ';

    return 0;
}