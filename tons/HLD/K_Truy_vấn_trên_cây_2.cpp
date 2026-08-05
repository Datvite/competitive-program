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
ii tree[4 * N];
int lazy[4 * N];
ii merge(ii a, ii b)
{
    ii res = {0, 0};
    res.fi = max(a.fi, b.fi);
    res.se = max(a.se, b.se);
    return res;
}
void update1(int node, int l, int r, int pos, int val)
{
    down(node, l, r);
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        tree[node].fi = val;
        tree[node].se = -val;
        return;
    }
    int mid = (l + r) / 2;
    update1(2 * node, l, mid, pos, val);
    update1(2 * node + 1, mid + 1, r, pos, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
void down(int node, int l, int r)
{
    if (lazy[node])
    {
        if (l != r)
        {
            swap(tree[2 * node].fi, tree[2 * node].se);
            lazy[2 * node] = lazy[2 * node] ^ 1;
            swap(tree[2 * node + 1].fi, tree[2 * node + 1].se);
            lazy[2 * node + 1] = lazy[2 * node + 1] ^ 1;
        }
        lazy[node] = 0;
    }
}
void update2(int node, int l, int r, int u, int v, int val)
{
    down(node, l, r);
    if (u > r || v < l)
        return;
    if (u <= l && r <= v)
    {
        swap(tree[node].fi, tree[node].se);
        lazy[node] = lazy[node] ^ 1;
        return;
    }
    int mid = (l + r) / 2;
    update2(2 * node, l, mid, u, v, val);
    update2(2 * node + 1, mid + 1, r, u, v, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
ii query(int node, int l, int r, int x, int y)
{
    down(node, l, r);
    if (x > r || y < l)
        return {-1e18, -1e18};
    if (x <= l && r <= y)
        return tree[node];
    int mid = (l + r) / 2;
    return merge(query(2 * node, l, mid, x, y), query(2 * node + 1, mid + 1, r, x, y));
}
int hget(int x, int y)
{
    int ans = -1e18;
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        ans = max(ans, query(1, 1, n, pos[headchain[chainID[y]]], pos[y]).fi);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
        ans = max(ans, query(1, 1, n, pos[x] + 1, pos[y]).fi);
    return ans;
}
void hupdate(int x, int y)
{
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        update2(1, 1, n, pos[headchain[chainID[y]]], pos[y], 1);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
        update2(1, 1, n, pos[x] + 1, pos[y], 1);
    return;
}
vector<iii> edge;
int un[N];
void reset()
{
    for (int i = 1; i <= 4 * n; i++)
    {
        tree[i] = {0, 0};
        lazy[i] = 0;
        depth[i] = 0;
        chainID[i] = 0;
        headchain[i] = 0;
        sz[i] = 0;
        pos[i] = 0;
        t[i] = 0;
        heavy[i] = 0;
        un[i] = 0;
        adj[i].clear();
    }
    edge.clear();
    curchain = 1;
    timer = 1;
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({w, {u, v}});
    }
    depth[1] = 0;
    dfs(1, 0);
    HLD(1, 0);
    int cnt = 1;
    for (auto [w, uv] : edge)
    {
        int u = uv.fi;
        int v = uv.se;
        if (depth[u] < depth[v])
            swap(u, v);
        un[cnt++] = u;
        a[pos[u]] = w;
    }
    for (int i = 1; i <= n; i++)
        update1(1, 1, n, pos[i], a[pos[i]]);
    string str;
    while (cin >> str)
    {
        if (str == "DONE")
            break;
        if (str == "CHANGE")
        {
            int i, v;
            cin >> i >> v;
            int u = un[i];
            update1(1, 1, n, pos[u], v);
        }
        else if (str == "NEGATE")
        {
            int x, y;
            cin >> x >> y;
            hupdate(x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (x == y)
                cout << 0 << endl;
            else
                cout << hget(x, y) << endl;
        }
    }
    reset();
}
main()
{
    skibidi;
    file("");
    int t;
    cin >> t;
    while (t--)
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
