#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

ll sum_of_subarray_differences(vector<int>& arr) {
    int n = arr.size();
    vector<int> left_max(n), right_max(n), left_min(n), right_min(n);
    stack<int> max_stack, min_stack;

    // Tìm số lần mỗi phần tử là max
    for (int i = 0; i < n; i++) {
        while (!max_stack.empty() && arr[max_stack.top()] < arr[i])
            max_stack.pop();
        left_max[i] = i - (max_stack.empty() ? -1 : max_stack.top());
        max_stack.push(i);
    }

    while (!max_stack.empty()) max_stack.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!max_stack.empty() && arr[max_stack.top()] <= arr[i])
            max_stack.pop();
        right_max[i] = (max_stack.empty() ? n : max_stack.top()) - i;
        max_stack.push(i);
    }

    // Tìm số lần mỗi phần tử là min
    for (int i = 0; i < n; i++) {
        while (!min_stack.empty() && arr[min_stack.top()] > arr[i])
            min_stack.pop();
        left_min[i] = i - (min_stack.empty() ? -1 : min_stack.top());
        min_stack.push(i);
    }
    
    while (!min_stack.empty()) min_stack.pop();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!min_stack.empty() && arr[min_stack.top()] >= arr[i])
            min_stack.pop();
        right_min[i] = (min_stack.empty() ? n : min_stack.top()) - i;
        min_stack.push(i);
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += (ll)arr[i] * (1ll * left_max[i] * right_max[i] - 1ll * left_min[i] * right_min[i]);
    }
    return total;
}

int main() {
    freopen("15C.inp", "r", stdin);
    freopen("15C.ans", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << sum_of_subarray_differences(arr) << endl;
    return 0;
}
