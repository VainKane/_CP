#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "TASKNAME"
#define sp ' '
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class T> bool mini(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <class T> bool maxi(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
using pii = pair<int, int>;

void enter() {

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w",  stdout);
    }
    
    enter();



    return 0;
}