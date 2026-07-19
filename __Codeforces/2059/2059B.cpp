#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_cost(const vector<int>& b) {
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] != i + 1) {
            return i + 1;
        }
    }
    return b.size() + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int min_cost = n + 1; 
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            if (__builtin_popcount(i) != k - 1) continue;

            vector<vector<int>> subarrays;
            vector<int> current_subarray;
            current_subarray.push_back(a[0]);
            for (int j = 0; j < n - 1; ++j) {
                if ((i >> j) & 1) {
                    subarrays.push_back(current_subarray);
                    current_subarray.clear();
                }
                current_subarray.push_back(a[j + 1]);
            }
            subarrays.push_back(current_subarray);

            if (subarrays.size() != k) continue;

            vector<int> b;
            for (int j = 1; j < k; j += 2) {
                b.insert(b.end(), subarrays[j].begin(), subarrays[j].end());
            }
            b.push_back(0);
            min_cost = min(min_cost, calculate_cost(b));
        }
        cout << min_cost << endl;
    }
    return 0;
}