/*
⠈⠙⠲⢶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⡀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⣼⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⠟⠓⠉
⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⢀⣧⣶⣦⣇⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣾⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠛⠛⠛⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠛⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀⠀
*/
#include<bits/stdc++.h>
using namespace std;
// Nishant Lamba...
#define int long long
#define vec vector<int>
#define vvec vector<vec>
#define pb push_back
#define endl '\n'

template<class T>
using p_queue = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e17;

void n_lamba_29(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<vvec>> adj(n+1, vector<vvec>(26));
    for(int i=0;i<m;i++){
        int u,v,w;
        char ch;
        cin>>u>>v>>w>>ch;
        adj[u][ch-'a'].pb({v,w});
        adj[v][ch-'a'].pb({u,w});
    }

    p_queue<vec> pq;
    vector<vec> dist(n+1, vec(n+1, inf));
    pq.push({0, s, t});
    dist[s][t] = 0;

    while(pq.size()){
        int cost = pq.top()[0];
        int ff = pq.top()[1];
        int ss = pq.top()[2];
        pq.pop();
        if(dist[ff][ss] < cost) continue;
        for(int i=0;i<26;i++){
            for(auto node1 : adj[ff][i]){
                for(auto node2 : adj[ss][i]){
                    int u = node1[0], v = node2[0];
                    int wt1 = node1[1], wt2 = node2[1];
                    if(dist[u][v] > dist[ff][ss] + wt1 + wt2){
                        dist[u][v] = dist[ff][ss] + wt1 + wt2;
                        pq.push({dist[u][v], u, v});
                    }
                }
            }
        }
    }

    int ans = inf;
    for(int i=1;i<=n;i++){
        ans = min(ans, dist[i][i]);
        for(int j=0;j<26;j++){
            for(auto it : adj[i][j]){
                int wt = it[1];
                int v = it[0];
                ans = min(ans, wt + dist[i][v]);
            }
        }
    }

    cout<<(ans == inf ? -1 : ans)<<endl;

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin>>test_cases;
    while(test_cases-->0)
    n_lamba_29();

    return 0;
}
// Nishant ...