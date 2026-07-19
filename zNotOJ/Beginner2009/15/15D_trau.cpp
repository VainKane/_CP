#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int MAX_BITS = 30;  // Vì a[i] ≤ 10^9 nên tối đa 30 bit là đủ
const int MAX_NODES = MAX_N * (MAX_BITS + 1);  // Số nút tối đa trong Trie

int child[MAX_NODES][2], count1[MAX_NODES];  
int nodeCount = 1;  // Bắt đầu từ 1 (nút gốc)

// Hàm thêm một số vào Trie
void insert(int num) {
    int node = 1;  // Bắt đầu từ gốc
    for (int i = MAX_BITS; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!child[node][bit]) {
            child[node][bit] = ++nodeCount;  // Tạo nút mới nếu chưa có
        }
        node = child[node][bit];
        count1[node]++;
    }
}

// Hàm đếm số lượng prefix[j] sao cho (prefix[i] ⊕ prefix[j]) < K
int countLessThan(int num, int K) {
    int node = 1, result = 0;
    for (int i = MAX_BITS; i >= 0; i--) {
        if (!node) break;
        int bitNum = (num >> i) & 1;
        int bitK = (K >> i) & 1;

        if (bitK == 1) {
            // Nếu bit K = 1, ta có thể lấy toàn bộ nhánh bitNum
            if (child[node][bitNum]) result += count1[child[node][bitNum]];
            node = child[node][1 - bitNum];  // Đi nhánh còn lại
        } else {
            node = child[node][bitNum];  // Chỉ có thể đi xuống nhánh bitNum
        }
    }
    return result;
}

int countSubarrays(int n, int K, vector<int>& arr) {
    memset(child, 0, sizeof(child));  // Xóa Trie trước khi chạy
    memset(count1, 0, sizeof(count1));
    nodeCount = 1;  // Reset node count

    insert(0);  // Khởi tạo Trie với prefix = 0
    int prefix = 0, result = 0;

    for (int num : arr) {
        prefix ^= num;
        result += countLessThan(prefix, K);
        insert(prefix);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, K;
    cin >> n >> K;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << countSubarrays(n, K, arr) << "\n";
    return 0;
}
