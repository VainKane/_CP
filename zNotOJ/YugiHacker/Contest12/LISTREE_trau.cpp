#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "listree"
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sp ' '
#define endl '\n'
#define cend cout << '\n';

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;
using vi2d = vector<vector<int>>;

const int maxn = 1e5 + 5;
int n;
int p[maxn], a[maxn];

void enter() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(TASKNAME ".inp", "r")) {
    freopen(TASKNAME ".inp", "r", stdin);
    freopen(TASKNAME ".ans", "w", stdout);
  }
  cin >> n;
  for (int i = 2; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
}

vi b;

int lis() {
  vi temp;
  for (int i = 0; i < b.size(); ++i) {
    auto it = lower_bound(temp.begin(), temp.end(), b[i]);
    if (it == temp.end())
      temp.pb(b[i]);
    else
      *it = b[i];
  }
  return temp.size();
}

void solve() {
  for (int u = 2; u <= n; ++u) {
    b.clear();
    int i = u;
    do {
      b.pb(a[i]);
    } while (i = p[i]);
    reverse(all(b));
    cout << lis() << sp;
  }
}

int main() {
  enter();
  solve();
  return 0;
}