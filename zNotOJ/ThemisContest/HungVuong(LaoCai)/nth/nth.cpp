#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using ld = long double;

template<class U, class V>
bool minz(U &a, V b) { return a > b ? a = b, 1 : 0; };

const int inf = 1e9 + 7;

int main() {
  #define taskname "nth"
  for (string iext : {"in", "inp"}) {
    if (fopen((taskname"." + iext).c_str(), "r")) {
      freopen((taskname"." + iext).c_str(), "r", stdin);
      freopen(taskname".out", "w", stdout);
      break;
    }
  }

  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> K(n + 2);
  K[0] = -1; K[n + 1] = m;
  for (int i = 1; i <= n; i++) cin >> K[i];
  n += 2;

  vector< vector<int> > dp(n, vector<int>(n));
  for (int i = 2; i < n; i++) dp[i - 2][i] = K[i] > K[i - 2] + 2 ? K[i] - K[i - 2] - 1 : 0;
  for (int i = n - 4; ~i; i--) {
    for (int j = i + 3; j < n; j++) {
      dp[i][j] = inf;
      for (int k = i + 1; k < j; k++) minz(dp[i][j], dp[i][k] + dp[k][j]);
      dp[i][j] += K[j] - K[i] - 1;
    }
  }
  cout << dp[0][n - 1] << "\n";
  
  return 0;
}