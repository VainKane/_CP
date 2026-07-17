#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

void solve(){
	int N;
	cin >> N;
	vector<string> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	vector<vector<int> > ok(N, vector<int>(N));
	vector<vector<int> > adj(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ok[i][j] = S[i][j] == '1';
			if(ok[i][j]) adj[i].push_back(j);
		}
	}
	vector<int> nreach(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			nreach[i] += ok[i][j];
		}
	}
	vector<int> ord(N);
	for(int i = 0; i < N; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int x, int y) {
		return nreach[x] < nreach[y];
	});
	vector<int> ord_rev(ord.rbegin(), ord.rend());

	UF uf(N);
	vector<pair<int,int> > edges;
	for(int v : ord){
		auto tmp = ok[v];
		if(tmp[v] != 1){
			cout << "No" << '\n';
			return;
		}
		tmp[v] = 0;
		for(int w : ord_rev){
			if(v == w) continue;
			if(!tmp[w]) continue;
			edges.push_back({v, w});
			if(!uf.join(v, w)){
				cout << "No" << '\n';
				return;
			}
			for(int x : adj[w]){
				if(!tmp[x]){
					cout << "No" << '\n';
					return;
				}
				tmp[x] = 0;
			}
		}
		if(tmp != vector<int>(N, 0)){
			cout << "No" << '\n';
			return;
		}
	}
	if(edges.size() != N-1){
		cout << "No" << '\n';
		return;
	}
	cout << "Yes" << '\n';
	for(auto [x, y] : edges){
		cout << (x+1) << ' ' << (y+1) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
