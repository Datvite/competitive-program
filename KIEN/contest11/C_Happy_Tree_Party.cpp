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
int n, q, a[N], under[N], w[N], u[N], v[N];
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
    if (tree[2 * node] == 0 || tree[2 * node + 1] == 0)
        tree[node] = 0;
    else if (2e18 / tree[2 * node] < tree[2 * node + 1])
        tree[node] = 2e18;
    else
        tree[node] = tree[2 * node] * tree[2 * node + 1];
}
int query(int node, int l, int r, int x, int y)
{
    if (x > r || y < l)
        return 1;
    if (x <= l && r <= y)
        return tree[node];
    int mid = (l + r) / 2;
    int left = query(2 * node, l, mid, x, y);
    int right = query(2 * node + 1, mid + 1, r, x, y);
    if (left == 0 || right == 0)
        return 0;
    if (2e18 / left < right)
        return 2e18;
    return left * right;
}
int hget(int x, int y)
{
    int ans = 1;
    for (; chainID[x] != chainID[y]; y = par[headchain[chainID[y]]])
    {
        if (depth[headchain[chainID[x]]] > depth[headchain[chainID[y]]])
            swap(x, y);
        int cur = query(1, 1, n, pos[headchain[chainID[y]]], pos[y]);
        if (cur == 0 || ans == 0)
            ans = 0;
        else if (2e18 / ans < cur)
            ans = 2e18;
        else
            ans *= cur;
    }
    if (depth[x] > depth[y])
        swap(x, y);
    if (pos[x] + 1 <= pos[y])
    {
        int cur = query(1, 1, n, pos[x] + 1, pos[y]);
        if (cur == 0 || ans == 0)
            ans = 0;
        else if (2e18 / ans < cur)
            ans = 2e18;
        else
            ans *= cur;
    }
    return ans;
}
void solve()
{
    for (int i = 1; i < n; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    depth[1] = 0;
    dfs(1, 0);
    HLD(1, 0);
    for (int i = 1; i < n; i++)
    {
        a[i] = w[i];
        if (depth[u[i]] < depth[v[i]])
            under[i] = v[i];
        else
            under[i] = u[i];
    }
    for (int i = 1; i < n; i++)
        update(1, 1, n, pos[under[i]], a[i]);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, v, k;
            cin >> u >> v >> k;
            int cur = hget(u, v);
            if (cur == 0 || cur > k)
                cout << 0 << endl;
            else
                cout << k / cur << endl;
        }
        else
        {
            int x, val;
            cin >> x >> val;
            update(1, 1, n, pos[under[x]], val);
        }
        // cout << type;
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
