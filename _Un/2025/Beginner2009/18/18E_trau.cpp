#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("18E.inp", "r", stdin);
    freopen("18E.ans", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    vector<char> digits;
    for (char c : s) {
        digits.push_back(c);
    }
    sort(digits.begin(), digits.end());

    queue<pair<string, int>> q;
    vector<bool> visited(n, false);

    // Handle first digits (non-zero)
    for (char c : digits) {
        if (c == '0') continue;
        int d = c - '0';
        int rem = d % n;
        if (rem == 0) {
            cout << c << endl;
            return 0;
        }
        if (!visited[rem]) {
            visited[rem] = true;
            q.push({string(1, c), rem});
        }
    }

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        string current_str = front.first;
        int current_rem = front.second;

        for (char c : digits) {
            int d = c - '0';
            int new_rem = (current_rem * 10 + d) % n;
            string new_str = current_str + c;

            if (new_rem == 0) {
                cout << new_str << endl;
                return 0;
            }

            if (!visited[new_rem]) {
                visited[new_rem] = true;
                q.push({new_str, new_rem});
            }
        }
    }

    cout << 0 << endl;
    return 0;
}