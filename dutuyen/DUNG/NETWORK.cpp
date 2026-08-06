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
struct edge
{
    int u, v, w;
} edges[N];
vector<ii> adj[N];
vector<int> vals;
int n, q;
int depth[N], up[N][21], tin[N], tout[N], timer = 0, under[N], weii[N], dtime[N];
struct PersistentSeg
{
    struct Node
    {
        int left, right, sum;
        Node() { left = right = sum = 0; }
    } node[N * 25];
    int numNode = 0;
    int version[N], versionET[N];
    int update(int l, int r, int pos, int oldver)
    {
        if (l == r)
        {
            node[++numNode] = node[oldver];
            node[numNode].sum++;
            return numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        if (pos <= mid)
        {
            node[id].left = update(l, mid, pos, node[oldver].left);
            node[id].right = node[oldver].right;
        }
        else
        {
            node[id].right = update(mid + 1, r, pos, node[oldver].right);
            node[id].left = node[oldver].left;
        }
        node[id].sum = node[node[id].left].sum + node[node[id].right].sum;
        return id;
    }
    int query(int ver, int l, int r, int u, int v)
    {
        if (!ver || u > r || v < l)
            return 0;
        if (u <= l && r <= v)
            return node[ver].sum;
        int mid = (l + r) / 2;
        return query(node[ver].left, l, mid, u, v) + query(node[ver].right, mid + 1, r, u, v);
    }

} seg;
void dfs(int u, int par)
{
    tin[u] = ++timer;
    dtime[timer] = u;
    for (int i = 1; i < 21; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto [v, id] : adj[u])
    {
        if (v != par)
        {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            under[id] = v;
            weii[v] = edges[id].w;
            dfs(v, u);
        }
    }
    tout[u] = timer;
}
void build(int u, int par)
{
    seg.version[u] = seg.update(1, n, weii[u], seg.version[par]);
    for (auto [v, id] : adj[u])
    {
        if (v != par)
            build(v, u);
    }
}
int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = 20; i >= 0; i--)
    {
        if (k >> i & 1)
            u = up[u][i];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
void solve()
{
    for (int i = 1; i < n; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        vals.push_back(edges[i].w);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for (int i = 1; i < n; i++)
    {
        edges[i].w = lower_bound(all(vals), edges[i].w) - vals.begin() + 1;
        adj[edges[i].u].push_back({edges[i].v, i});
        adj[edges[i].v].push_back({edges[i].u, i});
    }
    weii[1] = 0;
    dfs(1, 0);
    seg.version[0] = 0;
    build(1, 0);
    seg.versionET[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int u = dtime[i];
        seg.versionET[i] = seg.update(1, n, weii[u], seg.versionET[i - 1]);
    }
    while (q--)
    {
        char type;
        cin >> type;
        if (type == 'P')
        {
            int a, b, c;
            cin >> a >> b >> c;
            int comc = upper_bound(all(vals), c) - vals.begin();
            if (comc == 0)
                cout << 0 << endl;
            else
            {
                int lca = LCA(a, b);
                int ans = seg.query(seg.version[a], 1, n, 1, comc) + seg.query(seg.version[b], 1, n, 1, comc) - 2 * seg.query(seg.version[lca], 1, n, 1, comc);
                cout << ans << endl;
            }
        }
        else if (type == 'T')
        {
            int k, c;
            cin >> k >> c;
            int comc = upper_bound(all(vals), c) - vals.begin();
            if (comc == 0)
                cout << 0 << endl;
            else
            {
                int cur = edges[k].v;
                int child = under[k];
                int ans = 0;
                if (cur == child)
                {
                    int L = tin[child] + 1;
                    int R = tout[child];
                    if (L <= R)
                        ans = seg.query(seg.versionET[R], 1, n, 1, comc) - seg.query(seg.versionET[L - 1], 1, n, 1, comc);
                }
                else
                {
                    int inc = tin[child];
                    int outc = tout[child];
                    if (inc > 1)
                        ans += seg.query(seg.versionET[inc - 1], 1, n, 1, comc);
                    if (outc < n)
                        ans += seg.query(seg.versionET[n], 1, n, 1, comc) - seg.query(seg.versionET[outc], 1, n, 1, comc);
                }
                cout << ans << endl;
            }
        }
    }
}
main()
{
    skibidi;
    file("NETWORK");
    cin >> n >> q;
    solve();
}