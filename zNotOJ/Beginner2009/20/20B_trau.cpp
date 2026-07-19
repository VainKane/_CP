#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int parent[N];
int res[N];

int find(int u) {
    while (parent[u] != u) {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("20B.inp", "r", stdin);
    freopen("20B.ans", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n + 1; ++i) { // +1 để xử lý biên
        parent[i] = i;
    }

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        // Xử lý nửa trái [l, x-1]
        int i = find(l);
        while (i <= x - 1) {
            res[i] = x;
            parent[i] = find(i + 1);
            i = find(parent[i]);
        }

        // Xử lý nửa phải [x+1, r]
        i = find(x + 1);
        while (i <= r) {
            res[i] = x;
            parent[i] = find(i + 1);
            i = find(parent[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}