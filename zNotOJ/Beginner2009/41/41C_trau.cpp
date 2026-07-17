
#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define bit(x, i) ((x >> i) & 1)
#define il (node * 2)
#define ir (il + 1)
//#define mid (l + r)/2
#define maxn 200005
#define ll long long
#define pii pair <int, int>
#define MOD 1000000007
#define Task "kthnum"
//#define int long long
using namespace std;
int n, N, q;
int a[maxn], L[maxn], R[maxn], T[maxn];
vector <int> group[maxn], luu[maxn], c;
int b[maxn];

struct Data{
    int l, r, k;
} query[maxn];

pair <int, int> bs[maxn];

void update(int x, int y){
    while (x <= n){
        T[x] += y;
        x += (x & -x);
    }
}
int get(int x){
    int res = 0;
    while (x){
        res += T[x];
        x -= (x & -x);
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++){
        int pos = lower_bound(b+1, b+n+1, a[i]) - b;
        luu[pos].push_back(i);
    }
    for (int i = 1; i <= q; i++){
        cin >> query[i].l >> query[i].r >> query[i].k;
        bs[i] = {1,n+1}; // 2 diem tim nhi phan voi truy van i
    }
    for (int loop = 1; loop <= log2(n) + 2; loop++){
        for (int i = 1; i <= n; i++) group[i].clear();
        for (int i = 1; i <= q; i++){
            int mid = (bs[i].F + bs[i].S)/2;
            group[mid].PB(i);
        }

        memset(T, 0, sizeof(T));
        for (int i = 1; i <= n; i++){
            for (int u: group[i]){ // tru van thu u
                int cnt = get(query[u].r) - get(query[u].l-1);
                // so phan tu nho hon b[i] trong doan
                if (cnt >= query[u].k) bs[u].S = i;
                    else bs[u].F = i;// F -> gia thoa man
            }
            for (int pos: luu[i]) update(pos, 1);
            // update cac phan tu i vao BIT
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << b[bs[i].F] << "\n";
        // cerr << b[bs[i].F] << "\n";
    }
       
    return 0;
}
