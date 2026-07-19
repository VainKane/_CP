#include <bits/stdc++.h>
// using namespace std;

const int MAX_N = 300000;  // Số lượng truy vấn tối đa
const int MAX_BITS = 30;   // Vì 10^9 có tối đa 30 bit nhị phân
const int MAX_NODES = MAX_N * MAX_BITS;  // Số lượng nút tối đa cần dùng

int trie[MAX_NODES][2];  // Mảng lưu Trie, thay thế con trỏ
int count[MAX_NODES];    // Số phần tử trong mỗi nút
int tot = 1;             // Biến đếm số nút đã dùng (gốc là 1)

void insert(int x) {
    int node = 1;  // Bắt đầu từ gốc
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        int bit = (x >> i) & 1;  // Lấy bit thứ i của x
        if (!trie[node][bit]) trie[node][bit] = ++tot;  // Nếu chưa có, tạo nút mới
        node = trie[node][bit];
        count[node]++;  // Tăng số lượng phần tử tại nút này
    }
}

int findKth(int k) {
    int node = 1, num = 0;
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        int leftCount = trie[node][0] ? count[trie[node][0]] : 0;
        if (k <= leftCount) {
            node = trie[node][0];
        } else {
            k -= leftCount;
            num |= (1 << i);
            node = trie[node][1];
        }
    }
    return num;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("14D.inp", "r", stdin);
    freopen("14D.ans", "w", stdout);

    int N;
    std::cin >> N;

    while (N--) {
        int type, x;
        std::cin >> type >> x;
        if (type == 1) {
            insert(x);
        } else {
            std::cout << findKth(x) << '\n';
        }
    }

    return 0;
}
