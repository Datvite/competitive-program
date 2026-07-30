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
int n, m, q, a[N];
struct LCA
{
    static const int LOG = 20;

    int n;

    vector<vector<ii>> adj;
    vector<vector<int>> up, maxn;
    vector<int> depth;
    vector<bool> vis;
    LCA(int _n)
    {
        n = _n;
        vis.assign(n + 1, 0);
        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        maxn.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dfs(int u, int p, int val)
    {
        up[u][0] = p;
        vis[u] = 1;
        maxn[u][0] = val;
        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
            maxn[u][i] = max(maxn[u][i - 1], maxn[up[u][i - 1]][i - 1]);
        }

        for (auto edge : adj[u])
        {
            int v = edge.fi;
            int w = edge.se;
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, w);
        }
    }

    void build(int root = 1)
    {
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs(i, 0, 0);
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
        if (u == v)
            return 0;
        int res = 0;
        if (depth[u] < depth[v])
            swap(u, v);
        int k = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k >> i & 1)
            {
                res = max(res, maxn[u][i]);
                u = up[u][i];
            }
        }
        return res;
    }
};
struct DSU
{
    vector<int> par, sz;
    DSU(int _n)
    {
        n = _n;
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
};
vector<iii> edge;
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    DSU dsu(n);
    LCA lca(n);
    for (auto e : edge)
    {
        int w = e.fi;
        int u = e.se.fi;
        int v = e.se.se;
        if (dsu.acs(u) != dsu.acs(v))
        {
            dsu.join(u, v);
            lca.add_edge(u, v, w);
        }
    }
    lca.build();
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
        {
            cout << 0 << endl;
            continue;
        }
        if (dsu.acs(u) != dsu.acs(v))
        {
            cout << -1 << endl;
            continue;
        }
        int anc = lca.lca(u, v);
        cout << max(lca.dist(u, anc), lca.dist(v, anc)) << endl;
    }
}
main()
{
    skibidi;
    file("rescue");
    cin >> n >> m >> q;
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
