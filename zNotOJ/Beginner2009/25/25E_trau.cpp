/*
 *  DỜI ĐÔ – đường đi ngắn nhất từ S tới T,
 *  chọn đường đi ngắn nhất có thứ tự từ điển nhỏ nhất
 *  theo dãy các đỉnh được sắp tăng dần.
 *
 *  Thuật toán
 *  ----------
 *  1. BFS từ S → dista[] (khoảng cách) và ghi lại thứ tự BFS (order[]).
 *     Thứ tự này bảo đảm: độ sâu tăng dần.
 *  2. Duyệt order[] (bỏ qua S).  
 *     Với mỗi đỉnh u, tìm “cha” v (dista[v] = dista[u] − 1) sao cho
 *     đường S→v→u dẫn tới dãy đỉnh (sắp tăng) nhỏ nhất.  
 *     Hai đường được so sánh bằng đỉnh **nhỏ nhất** nằm trên phần khác
 *     biệt của chúng – thực hiện bởi hàm `better()` với binary‑lifting
 *     + mảng `upMin`.
 *  3. Truy vết ngược `par[]` từ T về S để in đáp án.
 *
 *  Độ phức tạp: O((N + M) log N) thời gian, O(N log N) bộ nhớ.
 */
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FAST_IO    ios_base::sync_with_stdio(false); cin.tie(0)

const int MAXN = 100000 + 5;
const int MAXM = 300000 * 2 + 5;
const int LOG  = 17;
const int INF  = 1e9;

struct Edge
{
    int to, nxt;
} e[MAXM];

int head[MAXN], ecnt;

inline void addEdge(int u, int v)
{
    e[++ecnt].to  = v;
    e[ecnt].nxt   = head[u];
    head[u]       = ecnt;
}

int n, m, S, T;

int dista[MAXN];            /* khoảng cách từ S */
int par[MAXN];              /* cha được chọn    */
int up[MAXN][LOG + 1];      /* tổ tiên 2^k      */
int upMin[MAXN][LOG + 1];   /* đỉnh nhỏ nhất trên đoạn tới tổ tiên 2^k */

int order[MAXN], orderCnt;  /* thứ tự BFS (độ sâu tăng dần)           */

/* Trả true nếu đường qua u “nhỏ” hơn qua v */
bool better(int u, int v)
{
    if (v == 0) return true;      /* u thắng khi v chưa gán  */
    if (u == 0) return false;     /* v đã có, u rỗng         */
    if (u == v) return false;

    int minU = INF, minV = INF;

    for (int k = LOG; k >= 0; --k)
        if (up[u][k] != up[v][k])
        {
            minU = std::min(minU, upMin[u][k]);
            minV = std::min(minV, upMin[v][k]);
            u = up[u][k];
            v = up[v][k];
        }

    minU = std::min(minU, u);
    minV = std::min(minV, v);
    return minU < minV;
}

/* BFS lấy dista[] và order[] */
void bfs_distance()
{
    std::queue<int> q;
    std::fill(dista, dista + n + 1, -1);

    dista[S] = 0;
    q.push(S);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        order[orderCnt++] = u;

        for (int id = head[u]; id; id = e[id].nxt)
        {
            int v = e[id].to;
            if (dista[v] == -1)
            {
                dista[v] = dista[u] + 1;
                q.push(v);
            }
        }
    }
}

/* Xây par[], up[], upMin[] */
void build_parents()
{
    /* Khởi tạo nút giả 0 */
    FOR(k, 0, LOG)
    {
        up[0][k]    = 0;
        upMin[0][k] = INF;
    }

    /* Root S */
    par[S]      = 0;
    up[S][0]    = 0;
    upMin[S][0] = S;
    FOR(k, 1, LOG)
    {
        up[S][k]    = 0;
        upMin[S][k] = S;
    }

    /* Duyệt các đỉnh theo độ sâu tăng dần (bỏ qua S ở order[0]) */
    for (int idx = 1; idx < orderCnt; ++idx)
    {
        int u    = order[idx];
        int best = 0;                       /* ứng viên cha tốt nhất */

        for (int id = head[u]; id; id = e[id].nxt)
        {
            int v = e[id].to;
            if (dista[v] == dista[u] - 1)   /* chỉ xét tầng trước   */
                if (better(v, best))
                    best = v;
        }

        par[u]      = best;
        up[u][0]    = best;
        upMin[u][0] = std::min(u, best);

        for (int k = 1; k <= LOG; ++k)
        {
            int p        = up[u][k - 1];
            up[u][k]     = up[p][k - 1];
            upMin[u][k]  = std::min(upMin[u][k - 1], upMin[p][k - 1]);
        }
    }
}

int main()
{
    FAST_IO;

    if (!(cin >> n >> m >> S >> T)) return 0;

    FOR(i, 1, m)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    bfs_distance();

    if (dista[T] == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    build_parents();

    /* Truy vết đường đi */
    int pathLen = dista[T] + 1;
    static int path[MAXN];

    int cur = T, idx = pathLen - 1;
    while (cur)
    {
        path[idx--] = cur;
        cur = par[cur];
    }

    FOR(i, 0, pathLen - 1) cout << path[i] << ' ';

    return 0;
}
