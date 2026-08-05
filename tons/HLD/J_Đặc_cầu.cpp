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
int n, m, q, u[N], v[N];
int chainID[N], headchain[N], pos[N], t[N], sz[N], par[N], curchain = 1, timer = 1, depth[N], heavy[N];
int cnt = 0, tplt = 0, d[N], low[N], scc[N], sz_scc[N];
stack<int> st;
vector<int> adj[N];
vector<ii> g[N];
void tarjan(int u, int edge)
{
    d[u] = low[u] = ++cnt;
    st.push(u);
    for (auto [v, id] : g[u])
    {
        if (id != edge)
        {
            if (d[v] != 0)
                low[u] = min(low[u], d[v]);
            else
            {
                tarjan(v, id);
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
            scc[v] = tplt;
            sz_scc[tplt]++;
        } while (u != v);
    }
}
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
int tree[4 * N], lazy[4 * N];
void down(int id, int l, int r)
{

    if (lazy[id] != 0)
    {
        int mid = (l + r) / 2;
        tree[2 * id] += lazy[id] * (mid - l + 1);
        tree[2 * id + 1] += lazy[id] * (r - mid);
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
        lazy[id] = 0;
    }
}
void update(int node, int l, int r, int u, int v, int val)
{
    down(node, l, r);
    if (u > r || v < l)
        return;
    if (u <= l && r <= v)
    {
        tree[node] += val * (r - l + 1);
        lazy[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, u, v, val);
    update(2 * node + 1, mid + 1, r, u, v, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int l, int r, int x, int y)
{
    down(node, l, r);
    if (x > r || y < l)
        return 0;
    if (x <= l && r <= y)
        return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, x, y) + query(2 * node + 1, mid + 1, r, x, y);
}
int hget(int x, int y)
{
    int ans = 0;
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        ans += query(1, 1, tplt, pos[headchain[chainID[y]]], pos[y]);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
        ans += query(1, 1, tplt, pos[x] + 1, pos[y]);
    return ans;
}
void hupdate(int x, int y, int val)
{
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        update(1, 1, tplt, pos[headchain[chainID[y]]], pos[y], val);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
        update(1, 1, tplt, pos[x] + 1, pos[y], val);
    return;
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].push_back({v[i], i});
        g[v[i]].push_back({u[i], i});
    }
    tarjan(1, 0);
    update(1, 1, tplt, 1, tplt, 1);
    for (int i = 1; i <= m; i++)
    {
        if (scc[u[i]] != scc[v[i]])
        {
            adj[scc[u[i]]].push_back(scc[v[i]]);
            adj[scc[v[i]]].push_back(scc[u[i]]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    depth[scc[1]] = 0;
    dfs(scc[1], 0);
    HLD(scc[1], 0);
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a = scc[a];
        b = scc[b];
        c = scc[c];
        d = scc[d];
        hupdate(a, b, -1);
        cout << hget(c, d) << endl;
        hupdate(a, b, 1);
    }
}
main()
{
    skibidi;
    file("");
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
