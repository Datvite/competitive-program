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
struct Trie
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
}
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
struct SegTreeBeats {
    static const long long INF = (1LL << 60);

    struct Node {
        long long sum;
        long long mx, mx2;
        int cnt;
    };

    int n;
    vector<Node> st;

    SegTreeBeats(int _n) {
        n = _n;
        st.assign(4 * n + 5, {0, -INF, -INF, 0});
    }

    Node merge(Node a, Node b) {
        Node res;
        res.sum = a.sum + b.sum;

        if (a.mx == b.mx) {
            res.mx = a.mx;
            res.cnt = a.cnt + b.cnt;
            res.mx2 = max(a.mx2, b.mx2);
        }
        else if (a.mx > b.mx) {
            res.mx = a.mx;
            res.cnt = a.cnt;
            res.mx2 = max(a.mx2, b.mx);
        }
        else {
            res.mx = b.mx;
            res.cnt = b.cnt;
            res.mx2 = max(a.mx, b.mx2);
        }

        return res;
    }

    void build(int id, int l, int r, vector<long long> &a) {
        if (l == r) {
            st[id] = {a[l], a[l], -INF, 1};
            return;
        }

        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);

        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void apply(int id, long long x) {
        if (st[id].mx <= x) return;

        st[id].sum -= 1LL * (st[id].mx - x) * st[id].cnt;
        st[id].mx = x;
    }

    void push(int id) {
        apply(id << 1, st[id].mx);
        apply(id << 1 | 1, st[id].mx);
    }

    void chmin(int id, int l, int r, int u, int v, long long x) {
        if (r < u || v < l || st[id].mx <= x)
            return;

        if (u <= l && r <= v && st[id].mx2 < x) {
            apply(id, x);
            return;
        }

        push(id);

        int mid = (l + r) >> 1;
        chmin(id << 1, l, mid, u, v, x);
        chmin(id << 1 | 1, mid + 1, r, u, v, x);

        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    long long query(int id, int l, int r, int u, int v) {
        if (r < u || v < l)
            return 0;

        if (u <= l && r <= v)
            return st[id].sum;

        push(id);

        int mid = (l + r) >> 1;
        return query(id << 1, l, mid, u, v)
             + query(id << 1 | 1, mid + 1, r, u, v);
    }

    // Wrapper
    void build(vector<long long> &a) {
        build(1, 1, n, a);
    }

    void chmin(int l, int r, long long x) {
        chmin(1, 1, n, l, r, x);
    }

    long long query(int l, int r) {
        return query(1, 1, n, l, r);
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
struct Matrix {
    std::vector<std::vector<long long>> a;
    int r, c;
    
    Matrix(int r, int c, bool is_identity = false) : r(r), c(c) {
        a.assign(r, std::vector<long long>(c, 0));
        if (is_identity) {
            for (int i = 0; i < std::min(r, c); i++) a[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(r, other.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < other.c; j++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix power(long long p) {
        Matrix res(r, c, true);
        Matrix base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
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
struct BigInt
{
    static const int base = 1000000000;
    static const int base_digits = 9;
    vector<int> a;
    int sign;

    BigInt() : sign(1) {}
    BigInt(long long v) { *this = v; }
    BigInt(const string &s) { read(s); }

    void operator=(long long v)
    {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        while (v > 0)
        {
            a.push_back(v % base);
            v /= base;
        }
    }

    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            pos++;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits)
        {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + (s[j] - '0');
            a.push_back(x);
        }
        trim();
    }

    void trim()
    {
        while (!a.empty() && a.back() == 0)
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const { return a.empty(); }

    friend ostream &operator<<(ostream &out, const BigInt &v)
    {
        if (v.sign == -1 && !v.isZero())
            out << '-';
        if (v.a.empty())
            out << 0;
        else
        {
            out << v.a.back();
            for (int i = (int)v.a.size() - 2; i >= 0; i--)
                out << setw(base_digits) << setfill('0') << v.a[i];
        }
        return out;
    }

    friend istream &operator>>(istream &in, BigInt &v)
    {
        string s;
        in >> s;
        v.read(s);
        return in;
    }

    static int absCmp(const BigInt &a, const BigInt &b)
    {
        if (a.a.size() != b.a.size())
            return a.a.size() < b.a.size() ? -1 : 1;
        for (int i = (int)a.a.size() - 1; i >= 0; i--)
            if (a.a[i] != b.a[i])
                return a.a[i] < b.a[i] ? -1 : 1;
        return 0;
    }

    bool operator<(const BigInt &v) const
    {
        if (sign != v.sign)
            return sign < v.sign;
        int cmp = absCmp(*this, v);
        return sign == 1 ? (cmp < 0) : (cmp > 0);
    }
    bool operator>(const BigInt &v) const { return v < *this; }
    bool operator<=(const BigInt &v) const { return !(v < *this); }
    bool operator>=(const BigInt &v) const { return !(*this < v); }
    bool operator==(const BigInt &v) const { return sign == v.sign && a == v.a; }
    bool operator!=(const BigInt &v) const { return !(*this == v); }

    BigInt operator-() const
    {
        BigInt res = *this;
        if (!res.isZero())
            res.sign = -sign;
        return res;
    }

    BigInt operator+(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            BigInt res = v;
            int carry = 0;
            for (size_t i = 0; i < max(a.size(), v.a.size()) || carry; i++)
            {
                if (i == res.a.size())
                    res.a.push_back(0);
                long long sum = res.a[i] + carry + (i < a.size() ? a[i] : 0LL);
                carry = sum >= base;
                if (carry)
                    sum -= base;
                res.a[i] = (int)sum;
            }
            return res;
        }
        return *this - (-v);
    }

    BigInt operator-(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            if (absCmp(*this, v) >= 0)
            {
                BigInt res = *this;
                int carry = 0;
                for (size_t i = 0; i < v.a.size() || carry; i++)
                {
                    long long sub = res.a[i] - (i < v.a.size() ? v.a[i] : 0) - carry;
                    carry = sub < 0;
                    if (carry)
                        sub += base;
                    res.a[i] = (int)sub;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    BigInt operator*(const BigInt &v) const
    {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.assign(a.size() + v.a.size(), 0);
        for (size_t i = 0; i < a.size(); i++)
        {
            long long carry = 0;
            for (size_t j = 0; j < v.a.size() || carry; j++)
            {
                long long cur = res.a[i + j] + (long long)a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
                res.a[i + j] = int(cur % base);
                carry = cur / base;
            }
        }
        res.trim();
        return res;
    }

    BigInt operator/(int v) const
    {
        BigInt res = *this;
        res.sign *= (v < 0 ? -1 : 1);
        v = abs(v);
        long long rem = 0;
        for (int i = (int)res.a.size() - 1; i >= 0; i--)
        {
            long long cur = res.a[i] + rem * base;
            res.a[i] = int(cur / v);
            rem = cur % v;
        }
        res.trim();
        return res;
    }

    int operator%(int v) const
    {
        long long m = 0;
        for (int i = (int)a.size() - 1; i >= 0; i--)
            m = (a[i] + m * base) % v;
        return (int)(m * sign);
    }
};
int chainID[N], headchain[N], pos[N], t[N], sz[N], par[N], curchain = 1, timer = 1, depth[N], heavy[N];
vector<int> adj[N];
void dfs(int u, int p)
{
    par[u] = p;
    sz[u] = 1;
    int mx = 0;
    for (int v : adj[u])
    {
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            if (sz[v] > sz[mx])
                mx = v;
            sz[u] += sz[v];
        }
    }
    heavy[u] = mx;
}
void HLD(int u, int p)
{
    if (!headchain[curchain])
        headchain[curchain] = u;
    chainID[u] = curchain;
    pos[u] = timer;
    t[timer] = u;
    timer++;
    int bigC = heavy[u];
    if (bigC)
        HLD(bigC, u);
    for (auto v : adj[u])
    {
        if (v != p && v != bigC)
        {
            curchain++;
            HLD(v, u);
        }
    }
}
int tree[4 * N];
void update(int node, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, pos, val);
    update(2 * node + 1, mid + 1, r, pos, val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int l, int r, int x, int y)
{
    if (x > r || y < l)
        return -1e9;
    if (x <= l && r <= y)
        return tree[node];
    int mid = (l + r) / 2;
    return min(query(2 * node, l, mid, x, y), query(2 * node + 1, mid + 1, r, x, y));
}
int hget(int x, int y)
{
    int ans = 0;
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        ans += query(1, 1, n, pos[headchain[chainID[y]]], pos[y]);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
        ans += query(1, 1, n, pos[x] + 1, pos[y]);
    return ans;
}
struct PersistentSeg
{
    struct Node
    {
        int left, right, sum;
        Node() {left = right = sum = 0;}
        Node(int _sum) : left(0), right(0), sum(_sum) {};
    } node[N * 25];
    int numNode = 0, numVer = 0;
    int version[N]; // root cua i
    void merge(int id)
    {
        node[id].sum = node[node[id].left].sum + node[node[id].right].sum;
    }

    int build(int l, int r)
    {
        if (l == r)
        {
            node[++numNode] = Node(a[l]);
            return numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        node[id].left = build(l, mid);
        node[id].right = build(mid + 1, r);
        merge(id);
        return id;
    }

    int update(int l, int r, int pos, int val, int oldver)
    {
        if (l == r)
        {
            node[++numNode] = Node(val);
            return numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        if (pos <= mid)
        {
            node[id].left = update(l, mid, pos, val, node[oldver].left);
            node[id].right = node[oldver].right;
        }
        else
        {
            node[id].left = node[oldver].left;
            node[id].right = update(mid + 1, r, pos, val, node[oldver].right);
        }
        merge(id);
        return id;
    }

    int get(int ver, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return node[ver].sum;
        int mid = (l + r) / 2;
        return get(node[ver].left, l, mid, u, v) + get(node[ver].right, mid + 1, r, u, v);
    }

    void buildTree()
    {
        numVer = 1;
        version[1] = build(1, n);
    }

    void update(int ver, int pos, int val)
    {
        version[ver] = update(1, n, pos, val, version[ver]);
    }

    void copy(int ver)
    {
        version[++numVer] = version[ver];
    }

    int getsum(int ver, int l, int r)
    {
        return get(version[ver], 1, n, l, r);
    }
} seg;
vector<int> buildLPS(const string& P) {
    int m = P.length();
    vector<int> lps(m, 0);
    int len = 0; // Độ dài tiền tố trùng với hậu tố dài nhất hiện tại
    int i = 1;

    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Hàm tìm kiếm KMP: Trả về danh sách các chỉ số xuất hiện (0-indexed)
vector<int> KMP(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();
    vector<int> matches;

    if (m == 0 || n < m) return matches;

    vector<int> lps = buildLPS(P);
    int i = 0; // Chỉ số cho T
    int j = 0; // Chỉ số cho P

    while (i < n) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j); // Tìm thấy P tại vị trí i - j
            j = lps[j - 1]; // Tiếp tục tìm các khớp phía sau
        } else if (i < n && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Match {
    int start_pos;  // Vị trí bắt đầu (0-indexed)
    int pattern_id; // ID của chuỗi mẫu
};

class AhoCorasick {
private:
    struct Node {
        int next[ALPHABET_SIZE];
        int fail = 0;
        vector<int> output; // Danh sách ID các mẫu kết thúc tại node này

        Node() {
            fill(next, next + ALPHABET_SIZE, -1);
        }
    };

    vector<Node> trie;
    vector<int> pattern_lens; // Lưu độ dài từng mẫu để tính start_pos

public:
    AhoCorasick() {
        trie.emplace_back(); // Root = 0
    }

    // 1. Thêm mẫu vào Trie
    void insert(const string& p, int pattern_id) {
        int u = 0;
        for (char c : p) {
            int idx = c - 'a'; // Tùy chỉnh theo bộ ký tự (ví dụ: c - 'A', c - '0')
            if (trie[u].next[idx] == -1) {
                trie[u].next[idx] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].next[idx];
        }
        trie[u].output.push_back(pattern_id);

        if (pattern_id >= (int)pattern_lens.size()) {
            pattern_lens.resize(pattern_id + 1);
        }
        pattern_lens[pattern_id] = p.length();
    }

    // 2. Xây dựng Fail Links bằng BFS (Trie Graph)
    void build() {
        queue<int> q;

        for (int c = 0; c < ALPHABET_SIZE; ++c) {
            if (trie[0].next[c] != -1) {
                q.push(trie[0].next[c]);
            } else {
                trie[0].next[c] = 0;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Kế thừa output từ node fail
            for (int id : trie[trie[u].fail].output) {
                trie[u].output.push_back(id);
            }

            for (int c = 0; c < ALPHABET_SIZE; ++c) {
                int v = trie[u].next[c];
                if (v != -1) {
                    trie[v].fail = trie[trie[u].fail].next[c];
                    q.push(v);
                } else {
                    trie[u].next[c] = trie[trie[u].fail].next[c];
                }
            }
        }
    }

    // DẠNG 1: Trả về danh sách tất cả lần xuất hiện {start_pos, pattern_id}
    vector<Match> find_all(const string& T) {
        vector<Match> matches;
        int u = 0;

        for (int i = 0; i < (int)T.length(); ++i) {
            int idx = T[i] - 'a';
            u = trie[u].next[idx];

            for (int pattern_id : trie[u].output) {
                int len = pattern_lens[pattern_id];
                int start_pos = i - len + 1; // Quy về chỉ số bắt đầu 0-indexed
                matches.push_back({start_pos, pattern_id});
            }
        }
        return matches;
    }

    // DẠNG 2: Trả về mảng đếm tần suất xuất hiện của từng pattern_id
    vector<int> count_all(const string& T, int num_patterns) {
        vector<int> cnt(num_patterns, 0);
        int u = 0;

        for (int i = 0; i < (int)T.length(); ++i) {
            int idx = T[i] - 'a';
            u = trie[u].next[idx];

            for (int pattern_id : trie[u].output) {
                cnt[pattern_id]++;
            }
        }
        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    AhoCorasick ac;
    vector<string> patterns = {"he", "she", "his", "hers"};
    int num_patterns = patterns.size();

    for (int i = 0; i < num_patterns; ++i) {
        ac.insert(patterns[i], i);
    }
    ac.build();

    string text = "ahishers";

    // --- TEST DẠNG 1: Tìm vị trí ---
    cout << "=== DANG 1: TAT CA MATCHES (start_pos, pattern) ===\n";
    vector<Match> matches = ac.find_all(text);
    for (const auto& m : matches) {
        cout << "Pattern '" << patterns[m.pattern_id] 
             << "' (ID " << m.pattern_id << ")"
             << " bat dau tai chi so: " << m.start_pos << "\n";
    }

    // --- TEST DẠNG 2: Đếm số lần xuất hiện ---
    cout << "\n=== DANG 2: DEM TAN SUAT ===\n";
    vector<int> cnt = ac.count_all(text, num_patterns);
    for (int i = 0; i < num_patterns; ++i) {
        cout << "Pattern '" << patterns[i] << "': " << cnt[i] << " lan\n";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int N = 200005;
const int MAXBITS = 29; // Xử lý các số < 2^30 (~10^9)

struct PersistentTrie
{
    struct Node
    {
        int child[2];
        int count; // Số lượng số đi qua node này
        Node()
        {
            child[0] = child[1] = 0;
            count = 0;
        }
    } node[N * 32]; // Mỗi phép insert tốn khoảng (MAXBITS + 2) node

    int numNode = 0, numVer = 0;
    int version[N]; // Root của phiên bản i

    // Tạo phiên bản mới bằng cách thêm giá trị val vào phiên bản oldver
    int insert(int val, int oldver)
    {
        int id = ++numNode;
        node[id] = node[oldver]; // Copy dữ liệu từ node phiên bản cũ
        node[id].count++;        // Tăng tần suất số đi qua

        int cur = id;
        int old = oldver;

        for (int i = MAXBITS; i >= 0; --i)
        {
            int bit = (val >> i) & 1;

            // Tạo node mới cho nhánh bit hiện tại
            node[cur].child[bit] = ++numNode;

            // Node mới copy dữ liệu từ nhánh tương ứng của phiên bản cũ (nếu có)
            if (old != 0)
            {
                node[node[cur].child[bit]] = node[node[old].child[bit]];
            }

            // Giữ nguyên nhánh bit còn lại (trỏ về phiên bản cũ)
            if (old != 0)
            {
                node[cur].child[1 - bit] = node[old].child[1 - bit];
            }

            // Chuyển xuống mức tiếp theo
            cur = node[cur].child[bit];
            node[cur].count++;

            if (old != 0)
            {
                old = node[old].child[bit];
            }
        }
        return id;
    }

    // Khởi tạo gốc phiên bản 0
    void init()
    {
        numNode = 0;
        numVer = 0;
        version[0] = 0; // version 0 là trie rỗng (node 0)
    }

    // Thêm một số val và tạo phiên bản mới
    void add(int val, int prevVer)
    {
        version[++numVer] = insert(val, version[prevVer]);
    }

    // Tìm x trong khoảng phiên bản [verL, verR] sao cho (x ^ val) MAX
    // Chú ý: Khoảng phiên bản [L, R] tương ứng truyền vào (version[L - 1], version[R])
    int query_max_xor(int verL, int verR, int val)
    {
        int res = 0;
        int u_L = version[verL];
        int u_R = version[verR];

        for (int i = MAXBITS; i >= 0; --i)
        {
            int bit = (val >> i) & 1;
            int target_bit = 1 - bit; // Ưu tiên chọn bit ngược lại để XOR ra 1

            // Tần suất của nhánh target_bit trong khoảng phiên bản [verL + 1, verR]
            int count_in_range = node[node[u_R].child[target_bit]].count 
                               - node[node[u_L].child[target_bit]].count;

            if (count_in_range > 0)
            {
                res |= (1 << i);
                u_L = node[u_L].child[target_bit];
                u_R = node[u_R].child[target_bit];
            }
            else
            {
                u_L = node[u_L].child[bit];
                u_R = node[u_R].child[bit];
            }
        }
        return res;
    }
} trie;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    trie.init();

    vector<int> a = {2, 5, 1, 7, 4}; // Đánh số 1..n -> a[1]=2, a[2]=5, ...
    int n = a.size();

    // Thêm các phần tử theo thứ tự 1..n
    for (int i = 0; i < n; ++i)
    {
        // Thêm a[i] vào phiên bản i (kế thừa từ phiên bản i)
        trie.add(a[i], i); 
    }

    // Ví dụ: Tìm x trong đoạn a[2..4] (chứa {5, 1, 7}) sao cho (x ^ 3) MAX
    int L = 2, R = 4;
    int V = 3;

    // Đoạn [L, R] tương ứng với hiệu giữa phiên bản R và phiên bản L - 1
    int ans = trie.query_max_xor(L - 1, R, V);

    cout << "Max XOR voi " << V << " trong doan [" << L << ", " << R << "] là: " << ans << "\n";

    return 0;
}
struct line
{
    int a, b;
    line(int a, int b) : a(a), b(b) {}
    int cal(int x)
    {
        return a * x + b;
    }
    int slope()
    {
        return a;
    }
};
struct liChao
{
    vector<line> st;
    liChao() {}
    liChao(int _n)
    {
        st.assign(_n * 4, line(0, 0));
    }

    void addline(int id, line li, int l, int r)
    {
        if (l == r)
        {
            if (li.cal(l) > st[id].cal(l))
                st[id] = li;
            return;
        }
        int mid = (l + r) >> 1;
        if (li.cal(mid) > st[id].cal(mid))
            swap(li, st[id]);
        if (li.slope() < st[id].slope())
            addline(id << 1, li, l, mid);
        else
            addline(id << 1 | 1, li, mid + 1, r);
    }

    void update(int id, line li, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v)
        {
            addline(id, li, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, li, l, mid, u, v);
        update(id << 1 | 1, li, mid + 1, r, u, v);
    }

    int get(int id, int l, int r, int pos)
    {
        int res = st[id].cal(pos);
        if (l == r)
        {
            return res;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            res = get(id << 1, l, mid, pos);
        else
            res = get(id << 1 | 1, mid + 1, r, pos);
        return res;
    }
};