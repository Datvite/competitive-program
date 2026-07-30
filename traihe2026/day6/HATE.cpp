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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 3e5 + 69;
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
int t, n, a[N], b[N], node1, node2, eid;
long long dp[N][2], ans = 0;
set<int> adj[N];
vector<ii> g[N];
bool vis[N];
void dfs(int u, int parent)
{
    vis[u] = 1;
    for (auto [v, id] : g[u])
    {
        if (v == parent)
            continue;
        if (vis[v])
        {
            node1 = u, node2 = v, eid = id;
        }
        else
            dfs(v, u);
    }
    return;
}
void cal(int u, int parent, int nodeban, int edgeban)
{
    if (u == nodeban)
        dp[u][1] = -1e18;
    else
        dp[u][1] = a[u];
    dp[u][0] = 0;
    for (auto [v, id] : g[u])
    {
        if (v == parent || id == edgeban)
            continue;
        cal(v, u, nodeban, edgeban);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
void solve()
{
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        g[i].clear();
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if (b[i] != -1)
            adj[i].insert(b[i]);
    }
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto v : adj[i])
        {
            g[i].push_back({v, ++id});
            g[v].push_back({i, id});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            node1 = node2 = eid = 0;
            dfs(i, -1);
            if (eid == 0)
            {
                cal(i, 0, 0, 0);
                ans += max(dp[i][0], dp[i][1]);
            }
            else
            {
                cal(node1, 0, node2, eid);
                long long res = max(dp[node1][0], dp[node1][1]);
                cal(node2, 0, node1, eid);
                res = max(res, max(dp[node2][0], dp[node2][1]));
                ans += res;
            }
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
    {
        solve();
    }
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
