#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = 1;
        while (n < size) n <<= 1;
        tree.resize(2 * n, 0);
    }

    void update(int pos) {
        pos += n;
        tree[pos]++;
        for (pos >>= 1; pos >= 1; pos >>= 1) {
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l <= r) {
            if (l % 2 == 1) res += tree[l++];
            if (r % 2 == 0) res += tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("32B.inp", "r", stdin);
    freopen("32B.ans", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int m;
    cin >> m;
    vector<int> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    SegmentTree st(n);

    for (int ti : t) {
        int low = 0, high = n - 1;
        int pos = n; // Mặc định không tìm thấy
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = st.query(0, mid);
            int current_val = a[mid] - cnt;
            if (current_val >= ti) {
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int ans = n - pos;
        cout << ans << '\n';
        if (pos < n) {
            st.update(pos);
        }
    }

    return 0;
}