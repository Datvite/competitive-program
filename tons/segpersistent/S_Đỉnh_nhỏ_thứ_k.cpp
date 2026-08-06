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
vector<int> vals;
struct PersistentSeg
{
    struct Node
    {
        int left, right, sum;
        Node() { left = right = sum = 0; }
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
            return ++numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        node[id].left = build(l, mid);
        node[id].right = build(mid + 1, r);
        merge(id);
        return id;
    }

    int update(int l, int r, int pos, int oldver)
    {
        if (l == r)
        {
            node[++numNode] = Node(node[oldver].sum + 1);
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
            node[id].left = node[oldver].left;
            node[id].right = update(mid + 1, r, pos, node[oldver].right);
        }
        merge(id);
        return id;
    }

    int walk(int verLCA, int verL, int verR, int l, int r, int k, int lca)
    {
        if (l == r)
            return vals[l - 1];
        int mid = (l + r) / 2;
        bool check = (l <= a[lca] && a[lca] <= mid);
        int leftSum = node[node[verR].left].sum + node[node[verL].left].sum - 2 * node[node[verLCA].left].sum + check;
        if (k <= leftSum)
            return walk(node[verLCA].left, node[verL].left, node[verR].left, l, mid, k, lca);
        else
            return walk(node[verLCA].right, node[verL].right, node[verR].right, mid + 1, r, k - leftSum, lca);
    }

    void buildTree()
    {
        numVer = 0;
        version[0] = build(1, n);
    }

    void update(int newVer, int oldVer, int pos)
    {
        version[newVer] = update(1, n, pos, version[oldVer]);
    }

    void copy(int ver)
    {
        version[++numVer] = version[ver];
    }

    int walk(int l, int r, int k, int lca)
    {
        return walk(version[lca], version[l], version[r], 1, n, k, lca);
    }
} seg;
int depth[N], par[N][21];
vector<int> adj[N];
void dfs(int u, int p)
{
    for (int i = 1; i < 21; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    seg.update(u, par[u][0], a[u]);
    for (int v : adj[u])
        if (v != p)
        {
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            dfs(v, u);
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
            u = par[u][i];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    seg.buildTree();
    dfs(1, 0);
    while (q--)
    {
        int u, v, k;
        cin >> u >> v >> k;
        int lca = LCA(u, v);
        if (depth[u] + depth[v] - 2 * depth[lca] + 1 < k)
            cout << -1 << endl;
        else
            cout << seg.walk(u, v, k, lca) << endl;
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
