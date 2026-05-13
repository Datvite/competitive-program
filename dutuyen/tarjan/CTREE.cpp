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
int n, a[N], dist[N], maxn = 0, id, id1;
vector<int> adj[N], path, ans;
void dfs(int u, int par)
{
    for (int v : adj[u])
    {
        if (v != par)
        {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}
bool dfs2(int u, int v, int par)
{
    path.push_back(u);
    if (u == v)
    {
        ans = path;
        return 1;
    }
    for (int w : adj[u])
    {
        if (w != par)
        {
            if (dfs2(w, v, u))
                return 1;
        }
    }
    path.pop_back();
    return 0;
}
void solve()
{
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > maxn)
        {
            maxn = dist[i];
            id = i;
        }
    }
    for (int i = 1; i <= n; i++)
        dist[i] = 0;
    dfs(id, 0);
    maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > maxn)
        {
            maxn = dist[i];
            id1 = i;
        }
    }
    dfs2(id, id1, 0);
    maxn = ans.size();
    if (maxn % 2 == 1)
        cout << 1 << endl << ans[maxn / 2];
    else
    {
        cout << 2 << endl << min(ans[maxn / 2 - 1], ans[maxn / 2]) << " " << max(ans[maxn / 2 - 1], ans[maxn / 2]);
    }
}
main()
{
    skibidi;
    file("CTREE");
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl << 1;
        return 0;
    }
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
