#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 +5;
int const oo = 1e9 + 9;

struct SegmentTree
{
	vector<int> t, lz;
	int n;
	
	SegmentTree(int _n = 0)
	{
		n = _n;
		t.assign(4 * n, oo);
		lz.assign(4 * n, 0);
	}
	
	void Lazy(int v)
	{
		if (lz[v])
		{
			FOR(u, v << 1, v << 1 | 1) t[u] += lz[v], lz[u] += lz[v];
			lz[v] = 0;
		}
	}
	
	void Update(int v, int l, int r, int left, int right, int val)
	{
		if (l == r)
		{
			t[v] = val;
			return;
		}
		
		Lazy(v);
		int mid = l + r >> 1;
		
		Update(v << 1, l, mid, l, r, val);
		Update(v << 1 | 1, mid + 1, r, l, r, val);
	
		t[v] = min(t[v << 1], t[v << 1 | 1]);
	}

	int Get(int v, int l, int r, int left, int right)
	{
		if (l > right || r < left) return oo;
		if (left <= l && right >= r) return t[v];
		
		Lazy(v);
		int mid = l + r >> 1;
		
		int val1 = Get(v << 1, l, mid, left, right);
		int val2 = Get(v << 1 | 1, mid + 1, r, left, right);
		
		return min(val1, val2);
	}

	void Update(int l, int r, int val)
	{
		if (l > r || l < 1 || r > n) return;
		Update(1, 1, n, l, r, val);
	}
	
	int Get(int l, int r)
	{
		if (l > r) return oo;
		return Get(1, 1, n, l, r);
	}
};

int n;
int last[N], pre[N];
SegmentTree it;

bool Solve()
{
	it = SegmentTree(n);
	FOR(i, 1, n)
	{
		it.Update(pre[i] + 1, i, 1);
		it.Update(pre[pre[i]] + 1, pre[i], -1);
	
		if (!it.Get(1, n)) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >>t;
	while (t--)
	{
		memset(pre, 0, sizeof pre);
		
		cin >> n;
		FOR(i, 1, n)
		{
			int x; cin >> x;
			pre[i] = last[x];
			last[x] = i;
		}
			
		cout << (Solve() ? "YES\n" : "NO\n");
	}
			
	return 0;
}