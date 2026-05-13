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
struct Dinic
{
    struct Edge
    {
        int to, rev;
        long long cap;
    };

    int n, s, t;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    Dinic(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;

        adj.assign(n + 1, {});
        level.assign(n + 1, 0);
        ptr.assign(n + 1, 0);
    }

    void add_edge(int u, int v, long long cap)
    {
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto e : adj[u])
            {
                if (e.cap > 0 && level[e.to] == -1)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[t] != -1;
    }

    long long dfs(int u, long long flow)
    {
        if (u == t || flow == 0)
            return flow;

        for (int &i = ptr[u]; i < adj[u].size(); i++)
        {
            Edge &e = adj[u][i];

            if (level[e.to] != level[u] + 1 || e.cap <= 0)
                continue;

            long long pushed = dfs(e.to, min(flow, e.cap));

            if (pushed)
            {
                e.cap -= pushed;
                adj[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }

        return 0;
    }

    long long maxflow()
    {
        long long flow = 0;

        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);

            while (long long pushed = dfs(s, 1e18))
                flow += pushed;
        }

        return flow;
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