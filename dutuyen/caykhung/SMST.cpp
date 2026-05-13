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
int n, m, a[N], cnt = 0;
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
};
vector<iii> edges;
int ans = 0;
vector<ii> adj[2000];
bool vis[2000];
int maxn, cu, cv;
bool dfs(int u, int en, int cur)
{
    if (u == en)
    {
        maxn = cur;
        return 1;
    }
    vis[u] = 1;
    for (auto [v, w] : adj[u])
    {
        if (!vis[v])
            if (dfs(v, en, max(cur, w)))
            {
                if (w == maxn)
                {
                    cu = u;
                    cv = v;
                }
                return 1;
            }
    }
    return 0;
}
void rv(int u, int v, int w)
{
    for (auto it = adj[u].begin(); it != adj[u].end(); it++)
    {
        if (it->fi == v && it->se == w)
        {
            adj[u].erase(it);
            break;
        }
    }
    for (auto it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (it->fi == u && it->se == w)
        {
            adj[v].erase(it);
            break;
        }
    }
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int w = edges[i].fi, u = edges[i].se.fi, v = edges[i].se.se;
        if (dsu.acs(u) != dsu.acs(v))
        {
            dsu.join(u, v);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            ans += w;
            cnt++;
        }
        else
        {
            memset(vis, 0, sizeof vis);
            maxn = -1e18;
            dfs(u, v, 0);
            if (maxn > w)
            {
                rv(cu, cv, maxn);
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                ans = ans - maxn + w;
            }
        }
        if (cnt == n - 1)
            cout << ans << endl;
        else
            cout << 123456789123456789 << endl;
    }
}
main()
{
    skibidi;
    file("SMST");
    cin >> n >> m;
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
