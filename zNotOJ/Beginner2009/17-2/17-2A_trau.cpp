#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>

using namespace std;

const int BASE = 31;
const int MOD = 1e9 + 7;

// Hàm băm Rolling Hash
typedef long long ll;
ll getHash(const vector<int>& arr) {
    ll hashValue = 0, power = 1;
    for (int num : arr) {
        hashValue = (hashValue + num * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hashValue;
}

vector<int> possible_k_values(int n, const vector<int>& original, const vector<int>& modified) {
    vector<int> result;
    ll targetHash = getHash(modified);
    unordered_set<ll> seenHashes;
    
    for (int k = 1; k <= n; k++) {
        vector<int> temp = original;
        for (int i = 0; i <= n - k; i++) {
            reverse(temp.begin() + i, temp.begin() + i + k);
        }
        
        ll hashValue = getHash(temp);
        if (hashValue == targetHash && seenHashes.find(hashValue) == seenHashes.end()) {
            result.push_back(k);
            seenHashes.insert(hashValue);
        }
    }
    return result;
}

int main() {
    freopen("17-2A.inp", "r", stdin);
    freopen("17-2A.ans", "w", stdout);
    int n;
    cin >> n;
    vector<int> original(n), modified(n);
    for (int i = 0; i < n; i++) cin >> original[i];
    for (int i = 0; i < n; i++) cin >> modified[i];
    
    vector<int> valid_k = possible_k_values(n, original, modified);
    cout << valid_k.size() << "\n";
    for (int k : valid_k) cout << k << " ";
    
    return 0;
}
