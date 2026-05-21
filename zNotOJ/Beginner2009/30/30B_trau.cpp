#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int _n, vector<int>& _pos) : n(_n), pos(_pos) {
        min_pos.resize(4 * n);
        max_pos.resize(4 * n);
        build(1, 1, n);
    }

    void update(int val) {
        internal_update(1, 1, n, val);
    }

    pair<int, int> query(int a, int b) {
        return internal_query(1, 1, n, a, b);
    }

private:
    int n;
    vector<int>& pos;
    vector<int> min_pos;
    vector<int> max_pos;

    void build(int node, int l, int r) {
        if (l == r) {
            min_pos[node] = pos[l];
            max_pos[node] = pos[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        min_pos[node] = min(min_pos[2*node], min_pos[2*node+1]);
        max_pos[node] = max(max_pos[2*node], max_pos[2*node+1]);
    }

    void internal_update(int node, int l, int r, int val) {
        if (l == r) {
            min_pos[node] = pos[val];
            max_pos[node] = pos[val];
            return;
        }
        int mid = (l + r) / 2;
        if (val <= mid) {
            internal_update(2*node, l, mid, val);
        } else {
            internal_update(2*node+1, mid+1, r, val);
        }
        min_pos[node] = min(min_pos[2*node], min_pos[2*node+1]);
        max_pos[node] = max(max_pos[2*node], max_pos[2*node+1]);
    }

    pair<int, int> internal_query(int node, int l, int r, int a, int b) {
        if (r < a || l > b) {
            return {INT_MAX, INT_MIN};
        }
        if (a <= l && r <= b) {
            return {min_pos[node], max_pos[node]};
        }
        int mid = (l + r) / 2;
        auto left = internal_query(2*node, l, mid, a, b);
        auto right = internal_query(2*node+1, mid+1, r, a, b);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("30B.inp", "r", stdin);
    freopen("30B.ans", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> pos(n+1); // pos[value] = index in arr (0-based)
    for (int i = 0; i < n; ++i) {
        pos[arr[i]] = i;
    }

    SegmentTree st(n, pos);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--; // convert to 0-based indices
            int a = arr[x];
            int b = arr[y];
            swap(arr[x], arr[y]);
            pos[a] = y;
            pos[b] = x;
            st.update(a);
            st.update(b);
        } else {
            int a, b;
            cin >> a >> b;
            auto [min_p, max_p] = st.query(a, b);
            if (max_p - min_p + 1 == b - a + 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}