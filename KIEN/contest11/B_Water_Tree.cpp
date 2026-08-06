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
int n, a[N], q;
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
int tree[4 * N], lazy[4 * N];
void down(int node, int l, int r)
{
    if (lazy[node] == -1)
        return;
    tree[node] = lazy[node];
    if (l != r)
    {
        tree[2 * node] = lazy[node];
        lazy[2 * node] = lazy[node];
        tree[2 * node + 1] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = -1;
}
void update(int node, int l, int r, int u, int v, int val)
{
    down(node, l, r);
    if (u > r || v < l)
        return;
    if (u <= l && r <= v)
    {
        tree[node] = val;
        lazy[node] = val;
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
int hupdate(int x, int y, int val)
{
    int ans = 0;
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        update(1, 1, n, pos[headchain[chainID[y]]], pos[y], val);
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] <= pos[y])
        update(1, 1, n, pos[x], pos[y], val);
    return ans;
}
void solve()
{
    memset(lazy, -1, sizeof(lazy));
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 1;
    dfs(1, 0);
    HLD(1, 0);
    cin >> q;
    while (q--)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            update(1, 1, n, pos[x], pos[x] + sz[x] - 1, 1);
        }
        else if (type == 2)
        {
            cin >> x;
            hupdate(1, x, 0);
        }
        else
        {
            cin >> x;
            if (query(1, 1, n, pos[x], pos[x]))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
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
