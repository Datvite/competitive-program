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
int n, m, ans[N], x[N], u[N], v[N], depth[N], edge_up[N], par[N];
vector<ii> adj[N];
bool mark[N];
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
void dfs(int u, int parent, int d, int edge_id)
{
    depth[u] = d;
    par[u] = parent;
    edge_up[u] = edge_id;
    for (auto [v, id] : adj[u])
    {
        if (v != parent)
        {
            dfs(v, u, d + 1, id);
        }
    }
}
void solve()
{
    DSU dsu(n);
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> x[i];
        adj[u[x[i]]].push_back({v[x[i]], x[i]});
        adj[v[x[i]]].push_back({u[x[i]], x[i]});
        mark[x[i]] = 1;
    }
    dfs(1, 0, 0, 0);
    int cnt = 1;
    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
            continue;
        if (mark[i])
        {
            int U = u[i], V = v[i];
            if (depth[U] < depth[V])
                swap(U, V);
            dsu.par[dsu.acs(U)] = dsu.acs(par[U]);
            ans[i] = cnt++;
        }
        else
        {
            int U = dsu.acs(u[i]), V = dsu.acs(v[i]);
            vector<int> v;
            while (U != V)
            {
                if (depth[U] < depth[V])
                    swap(U, V);
                v.push_back(edge_up[U]);
                int tmp = dsu.acs(par[U]);
                dsu.par[U] = tmp;
                U = tmp;
            }
            sort(v.begin(), v.end());
            for (auto id : v)
            {
                ans[id] = cnt++;
            }
            ans[i] = cnt++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
}
main()
{
    skibidi;
    file("");
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
