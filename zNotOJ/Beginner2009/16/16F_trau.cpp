#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (((x) >> (i)) & 1)

int const N = 1e6 + 5;
int const maxLog = 20;

struct Node {
    char ch;
    int depth = 0;
};

Node node[N];
int pos[N], par[N], up[N][maxLog];
int ind = 0, n;

void Type(char ch) {
    pos[ind] = ind;
    node[pos[ind]].ch = ch;
    par[ind] = pos[ind - 1];
    node[ind].depth = node[par[ind]].depth + 1;

    up[ind][0] = par[ind];
    for (int v = 1; (1 << v) <= n; v++) {
        up[ind][v] = up[up[ind][v - 1]][v - 1];
    }
}

void Undo(int k) {
    pos[ind] = pos[ind - k - 1];
}

char Get(int x, int ind) {
    ind = pos[ind];
    int k = node[ind].depth - x - 1;

    for (int i = 0; i < maxLog; i++) {
        if (bit(i, k)) {
            ind = up[ind][i];
        }
    }

    return node[ind].ch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string type;
        cin >> type;

        if (type == "T") {
            char x;
            cin >> x;
            ind++;
            Type(x);
        } 
        else if (type == "U") {
            int k;
            cin >> k;
            ind++;
            Undo(k);
        } 
        else if (type == "P") {
            int x;
            cin >> x;
            cout << Get(x, ind) << '\n';
        }
    }

    return 0;
}
