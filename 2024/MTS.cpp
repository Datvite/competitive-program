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
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<ii, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD = 2e9 + 11;
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
int n, a[N], par[N], m, ans = 0;
vector<iii> edges;
vector<int> res;
int acs(int u)
{
    if (par[u] == u)
        return par[u];
    return par[u] = acs(par[u]);
}
void join(int u, int v)
{
    u = acs(u);
    v = acs(v);
    if (u != v)
    {
        par[v] = u;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    par[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{w, i}, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (auto e : edges)
    {
        int u = e.se.fi, v = e.se.se, w = e.fi.fi, id = e.fi.se;
        if (acs(u) != acs(v))
        {
            join(u, v);
            res.push_back(id);
            ans += w;
        }
    }
    cout << ans << endl;
    for (auto x : res)
    cout << x << endl;
}
main()
{
    skibidi;
    file("MST");
    cin >> n >> m;
    solve();
}
