#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define int long long
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
    return (a + b) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n, a[N];
void solve()
{

}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
struct DSU
{
    vector<int> par, sz;
    DSU(int n)
    {
        par.resize(n + 7);
        sz.resize(n + 7, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }

    int acs(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = acs(par[x]);
    }

    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
    
} dsu;
struct DSU
{
    vector<int> par, sz;
    stack<tuple<int, int, int>> st;
    int maxn = 0;
    DSU(int n)
    {
        maxn = 1;
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }

    int acs(int x)
    {
        while (x != par[x])
            x = par[x];
        return x;
    }

    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return;
        cnt++;
        if (sz[u] < sz[v])
            swap(u, v);
        st.push({v, par[v], sz[u]});
        par[v] = u;
        sz[u] += sz[v];
    }

    void rollback(int x)
    {
        while (x--)
        {
            auto [v, old_p, old_sz] = st.top();
            st.pop();
            if (v == -1)
                return;
            int u = par[v];
            par[v] = old_p;
            sz[u] = old_sz;
        }
    }
};
struct BIT
{
    vector<int> bit;
    BIT(int n)
    {
        bit.resize(n + 4, 0);
    }

    void up(int i, int k)
    {
        for (; i <= n; i += i & -i)
        {
            bit[i] += k;
        }
    }

    int get(int i)
    {
        int res = 0;
        for (; i; i -= i & -i)
        {
            res += bit[i];
        }
        return res;
    }

    int query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
struct Fenwick
{
    int n;
    vector<long long> bit;

    Fenwick(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void add(int i, long long val)
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    long long sum(int i)
    {
        long long res = 0;

        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }

    long long range_sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    int lower_bound(long long x)
    {
        int pos = 0;

        for (int i = 1 << 20; i > 0; i >>= 1)
        {
            if (pos + i <= n && bit[pos + i] < x)
            {
                x -= bit[pos + i];
                pos += i;
            }
        }

        return pos + 1;
    }
};
struct TarjanSCC
{
    int n, cnt = 0, tplt = 0;
    vector<vector<int>> adj;

    vector<int> d, low, scc, sz;
    vector<bool> outstack;
    stack<int> st;

    void init(int _n)
    {
        n = _n;
        adj.resize(n + 1);

        d.assign(n + 1, 0);
        low.assign(n + 1, 0);
        scc.assign(n + 1, 0);
        outstack.assign(n + 1, false);

        sz.resize(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u)
    {
        d[u] = low[u] = ++cnt;
        st.push(u);

        for (auto v : adj[u])
        {
            if (!outstack[v])
            {
                if (d[v] != 0)
                    low[u] = min(low[u], d[v]);
                else
                {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                }
            }
        }

        if (low[u] == d[u])
        {
            int v;
            ++tplt;

            do
            {
                v = st.top();
                st.pop();

                outstack[v] = true;
                scc[v] = tplt;
                sz[tplt]++;
            }
            while (u != v);
        }
    }

    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!d[i])
                dfs(i);
        }
    }
};
struct SegmentTree
{
    struct Node
    {
        long long val;
        Node(long long _val)
        {
            val = _val;
        }
    };
    int n;
    vector<Node> st;

    SegmentTree(int _n)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.val = a.val + b.val;
        return res;
    }

    void build(int id, int l, int r, vector<long long> &a)
    {
        if (l == r)
        {
            st[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            st[id] = Node(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(0);
        if (u <= l && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
struct SegmentTree
{
    struct Node
    {
        long long val;
        Node(long long _val = 0)
        {
            val = _val;
        }
    };

    int n;
    vector<Node> st;
    vector<long long> lazy;

    SegmentTree(int _n = 0)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, 0);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.val = a.val + b.val;
        return res;
    }

    void build(int id, int l, int r, vector<long long> &a)
    {
        if (l == r)
        {
            st[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void down(int id, int l, int r)
    {
        if (lazy[id] == 0)
            return;
        int mid = (l + r) >> 1;
        long long t = lazy[id];
        st[id << 1].val += (mid - l + 1) * t;
        lazy[id << 1] += t;
        st[id << 1 | 1].val += (r - mid) * t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            st[id].val += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(0);
        if (u <= l && r <= v)
            return st[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
struct BFS
{
    int n;
    vector<vector<int>> adj;
    vector<int> dist;
    BFS(int _n)
    {
        n = _n;
        adj.assign(n + 1, {});
        dist.assign(n + 1, -1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    void run(int s)
    {
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
};
struct GridBFS
{
    int n, m;
    vector<vector<char>> a;
    vector<vector<int>> dist;

    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    GridBFS(int _n, int _m)
    {
        n = _n;
        m = _m;
        a.assign(n + 1, vector<char>(m + 1));
        dist.assign(n + 1, vector<int>(m + 1, -1));
    }

    bool inside(int x, int y)
    {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    }

    void run(int sx, int sy)
    {
        queue<pair<int,int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!inside(nx, ny))
                    continue;
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
struct Dijkstra
{
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist;

    Dijkstra(int _n = 0)
    {
        n = _n;

        adj.assign(n + 1, {});
        dist.assign(n + 1, 1e18);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    void run(int s)
    {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != dist[u])
                continue;
            for (auto [v, w] : adj[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};
struct GridDijkstra
{
    int n, m;
    vector<vector<int>> a;
    vector<vector<long long>> dist;

    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    GridDijkstra(int _n = 0, int _m = 0)
    {
        n = _n;
        m = _m;

        a.assign(n + 1, vector<int>(m + 1));
        dist.assign(n + 1, vector<long long>(m + 1, 1e18));
    }

    bool inside(int x, int y)
    {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    }

    void run(int sx, int sy)
    {
        priority_queue<pair<long long, pair<int,int>>,vector<pair<long long, pair<int,int>>>,greater<pair<long long, pair<int,int>>>> pq;

        dist[sx][sy] = 0;
        pq.push({0, {sx, sy}});

        while (!pq.empty())
        {
            auto [du, cur] = pq.top();
            pq.pop();

            auto [x, y] = cur;

            if (du != dist[x][y])
                continue;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!inside(nx, ny))
                    continue;
                long long w = a[nx][ny];
                if (dist[nx][ny] > dist[x][y] + w)
                {
                    dist[nx][ny] = dist[x][y] + w;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
};
struct Kuhn
{
    int n, m;
    vector<vector<int>> adj;
    vector<int> matchX, matchY, vis;

    Kuhn(int _n, int _m)
    {
        n = _n;
        m = _m;

        adj.assign(n + 1, {});
        matchX.assign(n + 1, -1);
        matchY.assign(m + 1, -1);
        vis.assign(n + 1, 0);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool dfs(int u)
    {
        if (vis[u])
            return false;

        vis[u] = 1;

        for (int v : adj[u])
        {
            if (matchY[v] == -1 || dfs(matchY[v]))
            {
                matchX[u] = v;
                matchY[v] = u;
                return true;
            }
        }

        return false;
    }

    int max_matching()
    {
        int ans = 0;
        bool found = true;

        while (found)
        {
            found = false;
            fill(vis.begin(), vis.end(), 0);

            for (int u = 1; u <= n; u++)
            {
                if (matchX[u] == -1 && dfs(u))
                {
                    ans++;
                    found = true;
                }
            }
        }

        return ans;
    }
};
struct MinCostMaxFlow
{
    struct Edge
    {
        int to, rev;
        long long cap, cost;
    };

    int n, s, t;
    vector<vector<Edge>> adj;

    MinCostMaxFlow(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;

        adj.assign(n + 1, {});
    }

    void add_edge(int u, int v, long long cap, long long cost)
    {
        Edge a = {v, (int)adj[v].size(), cap, cost};
        Edge b = {u, (int)adj[u].size(), 0, -cost};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    pair<long long, long long> min_cost_max_flow()
    {
        long long flow = 0, cost = 0;

        vector<long long> dist(n + 1);
        vector<int> par(n + 1), parEdge(n + 1);

        while (true)
        {
            fill(dist.begin(), dist.end(), 1e18);
            dist[s] = 0;

            vector<bool> inq(n + 1, false);
            queue<int> q;

            q.push(s);
            inq[s] = true;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                inq[u] = false;

                for (int i = 0; i < adj[u].size(); i++)
                {
                    Edge &e = adj[u][i];

                    if (e.cap > 0 && dist[e.to] > dist[u] + e.cost)
                    {
                        dist[e.to] = dist[u] + e.cost;
                        par[e.to] = u;
                        parEdge[e.to] = i;

                        if (!inq[e.to])
                        {
                            inq[e.to] = true;
                            q.push(e.to);
                        }
                    }
                }
            }

            if (dist[t] == 1e18)
                break;

            long long pushed = 1e18;

            for (int v = t; v != s; v = par[v])
            {
                Edge &e = adj[par[v]][parEdge[v]];
                pushed = min(pushed, e.cap);
            }

            for (int v = t; v != s; v = par[v])
            {
                Edge &e = adj[par[v]][parEdge[v]];

                e.cap -= pushed;
                adj[v][e.rev].cap += pushed;

                cost += pushed * e.cost;
            }

            flow += pushed;
        }

        return {flow, cost};
    }
};
struct EulerTour
{
    int n, timer = 0;
    vector<vector<int>> adj;
    vector<int> tin, tout, euler;

    EulerTour(int _n)
    {
        n = _n;
        adj.assign(n + 1, {});
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        euler.resize(n + 1);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p)
    {
        tin[u] = ++timer;
        euler[timer] = u;

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
        }

        tout[u] = timer;
    }
};
struct HLD
{
    int n, timer = 0;

    vector<vector<int>> adj;

    vector<int> parent, depth, heavy;
    vector<int> head, pos, sz;

    HLD(int _n)
    {
        n = _n;

        adj.assign(n + 1, {});

        parent.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        heavy.assign(n + 1, -1);

        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        sz.assign(n + 1, 0);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int u, int p)
    {
        parent[u] = p;
        sz[u] = 1;

        int mx = 0;

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > mx)
            {
                mx = sub;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h)
    {
        head[u] = h;
        pos[u] = ++timer;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u])
        {
            if (v == parent[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    void build(int root = 1)
    {
        dfs(root, 0);
        decompose(root, root);
    }

    int lca(int u, int v)
    {
        while (head[u] != head[v])
        {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            u = parent[head[u]];
        }

        return (depth[u] < depth[v] ? u : v);
    }
};
struct CentroidDecomposition
{
    int n;

    vector<vector<int>> adj;

    vector<int> sz, parent;
    vector<bool> removed;

    CentroidDecomposition(int _n)
    {
        n = _n;

        adj.assign(n + 1, {});
        sz.assign(n + 1, 0);

        parent.assign(n + 1, 0);
        removed.assign(n + 1, false);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_size(int u, int p)
    {
        sz[u] = 1;

        for (int v : adj[u])
        {
            if (v == p || removed[v])
                continue;

            dfs_size(v, u);
            sz[u] += sz[v];
        }
    }

    int find_centroid(int u, int p, int total)
    {
        for (int v : adj[u])
        {
            if (v == p || removed[v])
                continue;

            if (sz[v] > total / 2)
                return find_centroid(v, u, total);
        }

        return u;
    }

    void build(int u, int p)
    {
        dfs_size(u, 0);

        int c = find_centroid(u, 0, sz[u]);

        parent[c] = p;
        removed[c] = true;

        for (int v : adj[c])
        {
            if (!removed[v])
                build(v, c);
        }
    }
};
struct Matrix
{
    int x[maxn][maxn];

    Matrix() {}

    Matrix(int a[maxn][maxn])
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                x[i][j] = a[i][j];
            }
        }
    }

    Matrix operator * (const Matrix &b) const
    {
        Matrix c;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c.x[i][j] = 0;

                for (int k = 1; k <= n; k++)
                {
                    c.x[i][j] = add(
                        c.x[i][j],
                        mul(x[i][k], b.x[k][j])
                    );
                }
            }
        }

        return c;
    }

    friend Matrix operator ^ (const Matrix &a, const int &b)
    {
        if (b == 1)
            return a;

        Matrix c = (a ^ (b / 2));

        if (b & 1)
            return c * c * a;

        return c * c;
    }
};
const int BLOCK = 320;

struct Query
{
    int l, r, id;
};

bool cmp(Query a, Query b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l < b.l;

    return ((a.l / BLOCK) & 1 ? a.r > b.r : a.r < b.r);
}

vector<Query> query;

void add(int pos)
{
    // thêm a[pos]
}

void remove(int pos)
{
    // xoá a[pos]
}

void mo()
{
    sort(query.begin(), query.end(), cmp);

    int L = 1;
    int R = 0;

    for (auto q : query)
    {
        while (L > q.l)
            add(--L);

        while (R < q.r)
            add(++R);

        while (L < q.l)
            remove(L++);

        while (R > q.r)
            remove(R--);

        // ans[q.id] = ...
    }
}
struct LCA
{
    static const int LOG = 20;

    int n;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(int _n)
    {
        n = _n;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p)
    {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            dfs(v, u);
        }
    }

    void build(int root = 1)
    {
        dfs(root, 0);
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int k = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k >> i & 1)
                u = up[u][i];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    int dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
string s;
long long dp[20][2][2];
bool vis[20][2][2];

long long dfs(int pos, int tight, int started)
{
    if (pos == (int)s.size())
        return 1; // tùy bài: đếm 1 số hợp lệ

    if (vis[pos][tight][started])
        return dp[pos][tight][started];

    vis[pos][tight][started] = true;

    long long res = 0;

    int lim = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= lim; d++)
    {
        int ntight = tight && (d == lim);
        int nstarted = started || (d != 0);

        res += dfs(pos + 1, ntight, nstarted);
    }

    return dp[pos][tight][started] = res;
}

long long calc(long long x)
{
    s = to_string(x);

    memset(vis, 0, sizeof(vis));

    return dfs(0, 1, 0);
}
string s;
long long dp[20][2];
bool vis[20][2];

long long dfs(int pos, int tight)
{
    if (pos == (int)s.size())
        return 1;

    if (vis[pos][tight])
        return dp[pos][tight];

    vis[pos][tight] = true;

    long long res = 0;

    int lim = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= lim; d++)
    {
        int ntight = tight && (d == lim);
        res += dfs(pos + 1, ntight);
    }

    return dp[pos][tight] = res;
}

long long calc(long long x)
{
    s = to_string(x);

    memset(vis, 0, sizeof(vis));

    return dfs(0, 1);
}
struct Dinic
{
    struct Edge
    {
        int to;
        long long cap, flow, rev;
    };
    int n, s, t;
    vector<std::vector<Edge>> adj;
    vector<int> level, ptr;
    const long long INF = 1e18;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(2 * n + 7);
        level.resize(2 * n + 7);
        ptr.resize(2 * n + 7);
    }
    void add_edge(int from, int to, long long cap)
    {
        adj[from].push_back({to, cap, 0, (long long)adj[to].size()});
        adj[to].push_back({from, 0, 0, (long long)adj[from].size() - 1});
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &edge : adj[v])
            {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1)
                {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed)
    {
        if (pushed == 0 || v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < adj[v].size(); ++cid)
        {
            auto &edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0)
                continue;
            long long push = dfs(tr, std::min(pushed, edge.cap - edge.flow));
            if (push == 0)
                continue;
            edge.flow += push;
            adj[tr][edge.rev].flow -= push;
            return push;
        }
        return 0;
    }

    long long max_flow()
    {
        long long flow = 0;
        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, INF))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};
#include <bits/stdc++.h>
using namespace std;

int main() {
    int l = 1, r = 100;

    while (l <= r) {
        int mid = (l + r) / 2;

        cout << "? " << mid << endl;
        cout.flush();          // hoặc fflush(stdout);

        char c;
        cin >> c;

        if (c == '=')
            break;
        else if (c == '<')
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << "! " << l << endl;
    cout.flush();
}
int fac[N], revfac[N];

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(int lim)
{
    fac[0] = 1;
    for (int i = 1; i <= lim; i++)
        fac[i] = fac[i - 1] * i % MOD;

    revfac[lim] = power(fac[lim], MOD - 2);
    for (int i = lim - 1; i >= 0; i--)
        revfac[i] = revfac[i + 1] * (i + 1) % MOD;
}

int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fac[n] * revfac[k] % MOD * revfac[n - k] % MOD;
}
int C[N][N];

void init()
{
    C[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}
struct Matrix
{
    int x[maxn][maxn];

    Matrix() {}

    Matrix(int a[maxn][maxn])
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                x[i][j] = a[i][j];
            }
        }
    }

    Matrix operator * (const Matrix &b) const
    {
        Matrix c;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c.x[i][j] = 0;

                for (int k = 1; k <= n; k++)
                {
                    c.x[i][j] = add(
                        c.x[i][j],
                        mul(x[i][k], b.x[k][j])
                    );
                }
            }
        }

        return c;
    }

    friend Matrix operator ^ (const Matrix &a, const int &b)
    {
        if (b == 1)
            return a;

        Matrix c = (a ^ (b / 2));

        if (b & 1)
            return c * c * a;

        return c * c;
    }
};
struct Hash
{
    const int base = 311;
    const int mod1 = 1000000007;
    const int mod2 = 1000000009;
    vector<int> pw1, pw2, h1, h2;
    inline int sub(int a, int b, int mod)
    {
        a %= mod;
        b %= mod;
        a -= b;
        if (a < 0)
            a += mod;
        return a;
    }
    inline int mul(int a, int b, int mod)
    {
        return (a % mod) * (b % mod) % mod;
    }
    Hash()
    {
        pw1.assign(n + 1, 0);
        pw2.assign(n + 1, 0);
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        pw1[0] = pw2[0] = 1;
        stack<int> st;
        for (int i = 1; i <= n; i++)
        {
            pw1[i] = pw1[i - 1] * base % mod1;
            pw2[i] = pw2[i - 1] * base % mod2;
            if (st.size() && st.top() + a[i] == k)
            {
                h1[i] = h1[i - 1];
                h2[i] = h2[i - 1];
                h1[i] = mul(sub(h1[i], st.top(), mod1), exp(base, mod1 - 2, mod1), mod1);
                h2[i] = mul(sub(h2[i], st.top(), mod2), exp(base, mod2 - 2, mod2), mod2);
                st.pop();
            }
            else
            {
                st.push(a[i]);
                h1[i] = (h1[i - 1] * base + a[i]) % mod1;
                h2[i] = (h2[i - 1] * base + a[i]) % mod2;
            }
        }
    }
    ii get(int l, int r)
    {
        int x1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod1;
        if (x1 < 0)
            x1 += mod1;
        int x2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod2;
        if (x2 < 0)
            x2 += mod2;
        return {x1, x2};
    }
};
const long long INF = 1e18;

void floydWarshall(int n, vector<vector<long long>> &dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
const int test = 100;

std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r)
{
    if (l > r)
    {
        std::swap(l, r);
    }
    std::uniform_int_distribution<int> dist(l, r);
    return dist(rd);
}

__Thien_dep_trai__
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    srand(time(0));
    for (int iTest = 1; iTest <= test; iTest++)
    {
        std::ofstream inp(task ".inp");

        inp.close();

        system(task ".exe");
        system(task "_trau.exe");
        if (system("fc " task ".out " task ".ans") != 0)
        {
            std::cout << "TEST " << iTest << ": WRONG ANSWER!\n";
            return 0;
        }
        std::cout << "TEST " << iTest << ": ACCEPTED!\n";
    }

    std::cerr << "\nTime elapsed: " << TIME << " s.\n";

    return 0;
}struct Trie
{
    struct Node
    {
        int child[26];
        int cntEnd;
        int cntPass;

        Node()
        {
            memset(child, -1, sizeof(child));
            cntEnd = cntPass = 0;
        }
    };

    vector<Node> trie;

    Trie()
    {
        trie.emplace_back(); // root
    }

    void insert(string s)
    {
        int u = 0;
        trie[u].cntPass++;
        for (char c : s)
        {
            int x = c - 'a';
            if (trie[u].child[x] == -1)
            {
                trie[u].child[x] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].child[x];
            trie[u].cntPass++;
        }
        trie[u].cntEnd++;
    }

    bool find(string s)
    {
        int u = 0;
        for (char c : s)
        {
            int x = c - 'a';
            if (trie[u].child[x] == -1)
                return false;
            u = trie[u].child[x];
        }
        return trie[u].cntEnd > 0;
    }

    bool erase(string s)
    {
        if (!find(s))
            return false;

        int u = 0;
        trie[u].cntPass--;
        for (char c : s)
        {
            int x = c - 'a';
            u = trie[u].child[x];
            trie[u].cntPass--;
        }
        trie[u].cntEnd--;
        return true;
    }

    int countWord(string s)
    {
        int u = 0;
        for (char c : s)
        {
            int x = c - 'a';
            if (trie[u].child[x] == -1)
                return 0;
            u = trie[u].child[x];
        }
        return trie[u].cntEnd;
    }

    int countPrefix(string s)
    {
        int u = 0;
        for (char c : s)
        {
            int x = c - 'a';
            if (trie[u].child[x] == -1)
                return 0;
            u = trie[u].child[x];
        }
        return trie[u].cntPass;
    }
};
const int MAXN = 200005;
const int LOGN = 19;

struct RMQ {
    int st[MAXN][LOGN];
    int lg[MAXN];

    void init(int n, int a[]) {
        lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        for (int i = 1; i <= n; i++) st[i][0] = a[i];

        for (int j = 1; j <= LOGN; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = lg[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
} rmq;