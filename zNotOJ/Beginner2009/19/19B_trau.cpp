#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("19B.inp", "r", stdin);
    freopen("19B.out", "w", stdout);

    int N, M, S, T;
    cin >> N >> M >> S >> T;

    if (S == T) {
        cout << "1000000000000000000\n1\n" << S << '\n';
        return 0;
    }

    vector<Edge> edges;
    int max_edge = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        if (w > max_edge) max_edge = w;
    }

    int low = 0, high = max_edge;
    int H = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        vector<vector<int>> adj(N + 1);
        for (auto& e : edges) {
            if (e.w >= mid) {
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
            }
        }

        vector<bool> visited(N + 1, false);
        queue<int> q;
        q.push(S);
        visited[S] = true;
        bool found = false;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == T) {
                found = true;
                break;
            }
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (found) {
            H = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (H == 0) {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> adj(N + 1);
    for (auto& e : edges) {
        if (e.w >= H) {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }
    }

    vector<int> parent(N + 1, -1);
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == T) break;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[T]) {
        cout << "0\n";
        return 0;
    }

    vector<int> path;
    int current = T;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << H << '\n';
    cout << path.size() << '\n';
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << path[i];
    }
    cout << '\n';

    return 0;
}
