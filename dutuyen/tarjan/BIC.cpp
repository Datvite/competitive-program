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
const int MOD = 1e9;
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
int n, m, a[N], dp[N];
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
            } while (u != v);
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
} tj;
bool vis[N],vis1[N], vis2[N];
void dfs(int u)
{
    vis1[u] = true;
    for (int v : tj.adj[u])
    {
        if (!vis1[v])
        {
            dfs(v);
        }
    }
}
void dfs2(int u)
{
    vis2[u] = true;
    for (int v : tj.adj[u])
    {
        if (!vis2[v])
        {
            dfs2(v);
        }
    }
}
vector<int> adj[N], topo;
void dfstopo(int u)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfstopo(v);
    topo.push_back(u);
}
void toposort(int n)
{
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfstopo(i);
    reverse(topo.begin(), topo.end());
}
void solve()
{
    tj.init(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        tj.addEdge(u, v);
    }
    tj.build();
    for (int i = 1; i <= n; i++)
    {
        for (int v : tj.adj[i])
        {
            if (tj.scc[i] != tj.scc[v])
            {
                adj[tj.scc[i]].push_back(tj.scc[v]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (tj.scc[i] == 1)
            dfs(i);
    for (int i = 1; i <= n; i++)
        if (tj.scc[i] == 2)
            dfs2(i);
    toposort(tj.tplt);
    for (int i = 1; i <= n; i++)
    {
        if (vis1[i] && vis2[i] && tj.sz[tj.scc[i]] > 1)
        {
            cout << -1;
            return;
        }
    }
    dp[tj.scc[1]] = 1;
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            dp[v] = add(dp[v], dp[u]);
        }
    }
    cout << dp[tj.scc[2]];
}
main()
{
    skibidi;
    file("BIC");
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
