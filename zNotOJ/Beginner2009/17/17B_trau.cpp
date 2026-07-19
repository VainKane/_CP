#include <bits/stdc++.h>
using namespace std;

string find_original_s(string u) {
    int n = u.size();
    set<string> possible_s;

    for (int i = 0; i < n; i++) {
        string v = u.substr(0, i) + u.substr(i + 1); // Loại bỏ ký tự u[i]
        int m = v.size();

        if (m % 2 == 1) continue; // Nếu độ dài không chẵn thì không thể là ss

        string s1 = v.substr(0, m / 2);
        string s2 = v.substr(m / 2);

        if (s1 == s2) possible_s.insert(s1);
    }

    if (possible_s.empty()) return "NOT POSSIBLE";
    if (possible_s.size() > 1) return "NOT UNIQUE";
    return *possible_s.begin();
}

int main() {
    freopen("17B.inp", "r", stdin);
    freopen("17B.ans", "w", stdout);

    string u;
    cin >> u;
    cout << find_original_s(u) << endl;
    return 0;
}
