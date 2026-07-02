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
int n, q, a[N], tin[N], tout[N], d[N], timer = 0;
vector<int> cnt[N], adj[N];
vector<vector<int>> up;
void dfs(int u, int par)
{
    tin[u] = ++timer;
    cnt[d[u]].push_back(tin[u]);
    up[u][0] = par;
    for (int i = 1; i < 20; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
    tout[u] = timer;
}
int get(int u, int k)
{
    for (int i = 0; i < 20; i++)
    {
        if ((k >> i) & 1)
            u = up[u][i];
    }
    return u;
}
void solve()
{
    up.assign(n + 1, vector<int>(20));
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
    }
    dfs(0, 0);
    cin >> q;
    while (q--)
    {
        int u, k;
        cin >> u >> k;
        if (k >= d[u])
        {
            cout << 0 << endl;
            continue;
        }
        int nu = get(u, k);
        auto id = lower_bound(cnt[d[u]].begin(), cnt[d[u]].end(), tin[nu]);
        auto id2 = upper_bound(cnt[d[u]].begin(), cnt[d[u]].end(), tout[nu]);
        cout << (id2 - id) - 1 << endl;

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
