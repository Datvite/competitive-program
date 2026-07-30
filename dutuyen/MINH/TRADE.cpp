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
int n, m, k, a[N], ans = 0;
struct DSU
{
    vector<int> par, sz;
    DSU(int n)
    {
        par.resize(n + 7);
        sz.resize(n + 7, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }
    int acs(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = acs(par[x]);
    }
    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};
vector<iii> adj;
void solve()
{
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    DSU dsu(n + 36);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    sort(adj.begin(), adj.end());
    for (int i = 1; i <= k; i++)
        dsu.join(a[i], n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = adj[i].se.fi;
        int v = adj[i].se.se;
        int w = adj[i].fi;
        if (dsu.acs(u) != dsu.acs(v))
        {
            dsu.join(u, v);
            //cout << u << " " << v << " " << w << endl;
            ans += w;
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("TRADE");
    cin >> n >> m >> k;
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
