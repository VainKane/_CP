#include <bits/stdc++.h>
using namespace std;

#define name "38D"

string t, p;
int n, m;
vector<int> pattern_code;
vector<int> text_code;
vector<int> res;

// Mã hóa chuỗi theo vị trí xuất hiện đầu tiên của ký tự
vector<int> encode(const string &s) {
    unordered_map<char, int> mp;
    vector<int> code(s.size());
    int id = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (mp.count(s[i]) == 0) {
            mp[s[i]] = id++;
        }
        code[i] = mp[s[i]];
    }
    return code;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> t >> p;
    n = t.size();
    m = p.size();

    pattern_code = encode(p);

    for (int i = 0; i + m <= n; ++i) {
        string sub = t.substr(i, m);
        text_code = encode(sub);
        if (text_code == pattern_code) {
            res.push_back(i + 1); // vị trí bắt đầu (1-indexed)
        }
    }

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';
    return 0;
}
