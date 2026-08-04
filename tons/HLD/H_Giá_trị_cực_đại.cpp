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
const int N = 2e5 + 69;
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
int n, q, a[N];
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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int l, int r, int x, int y)
{
    if (x > r || y < l)
        return -1e9;
    if (x <= l && r <= y)
        return tree[node];
    int mid = (l + r) / 2;
    return max(query(2 * node, l, mid, x, y), query(2 * node + 1, mid + 1, r, x, y));
}
int LCA(int u, int v)
{
    while (chainID[u] != chainID[v])
    {
        if (chainID[u] > chainID[v])
            u = par[headchain[chainID[u]]];
        else
            v = par[headchain[chainID[v]]];
    }
    if (depth[u] < depth[v])
        return u;
    return v;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 0;
    dfs(1, 0);
    HLD(1, 0);
    for (int i = 1; i <= n; i++)
        update(1, 1, n, pos[i], a[i]);
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int u, val;
            cin >> u >> val;
            update(1, 1, n, pos[u], val);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            int lca = LCA(u, v);
            int res1 = 0;
            while (chainID[u] != chainID[lca])
            {
                res1 = max(res1, query(1, 1, n, pos[headchain[chainID[u]]], pos[u]));
                u = par[headchain[chainID[u]]];
            }
            res1 = max(res1, query(1, 1, n, pos[lca], pos[u]));
            int res2 = 0;
            while (chainID[v] != chainID[lca])
            {
                res2 = max(res2, query(1, 1, n, pos[headchain[chainID[v]]], pos[v]));
                v = par[headchain[chainID[v]]];
            }
            res2 = max(res2, query(1, 1, n, pos[lca], pos[v]));
            cout << max(res1, res2) << " ";
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
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
