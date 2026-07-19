#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "brick"
#define ff first
#define ss second
#define pb push_back
#define sp ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using mii = map<int, int>;
using mll = map<long long, long long>;
using vi2d = vector<vector<int>>;

const int maxn = 1e6;
int t;
ll n;

void enter() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }
    cin >> t;    
}

bool sieve[maxn];
void genSieve() {
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < maxn; ++i) if (sieve[i]) for (int j = i * i; j < maxn; j += i) sieve[j] = 0;
}

vll mult;

void solveQuery() {
    cout << n - mult[upper_bound(all(mult), n) - mult.begin() - 1] << endl;
}

void solve() {
    genSieve();
    ll last = 2;
    for (int i = 3; i < maxn; ++i) if (sieve[i]) mult.pb(last * i), last = i;
    while (t--) {
        cin >> n;
        solveQuery();
    }
}

int main() {
    enter();
    solve();    
    return 0;
}