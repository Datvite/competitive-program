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
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e3 + 69;
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
int n, m, W, val[N], c[N], par[N], tplt, dp[N][1002];
vector<int> v[N];
int acs(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = acs(par[u]);
}
void join(int u, int v)
{
    u = acs(u);
    v = acs(v);
    if (u == v)
        return;
    par[v] = u;
    tplt--;
}
vector<int> comp[N], group;
void solve()
{
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    tplt = n;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    for (int i = 1; i <= n; i++)
        comp[acs(i)].push_back(i);
    for (int i = 1; i <= n; i++)
    {
        if (!comp[i].empty())
            group.push_back(i);
    }
    int res = 0;
    for (int i = 1; i <= group.size(); i++)
    {
        int sumc = 0, sumv = 0;
        for (int x : comp[group[i - 1]])
        {
            sumc += c[x];
            sumv += val[x];
        }
        for (int x : comp[group[i - 1]])
        {
            for (int w = W; w >= c[x]; w--)
            {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - c[x]] + val[x]);
            }
        }
        for (int w = W; w >= sumc; w--)
            dp[i][w] = max(dp[i][w], dp[i - 1][w - sumc] + sumv);
        res = max(res, dp[i][W]);
    }
    cout << res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> W;
    solve();
}
