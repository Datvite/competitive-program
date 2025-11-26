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
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1058576;
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
int n, m, dp[N][22];
vector<int> adj[22];
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dp[1][1] = 1;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (!(mask & (1 << (u - 1))))
                continue;
            for (int v : adj[u])
            {
                if (!(mask & (1 << (v - 1))))
                {
                    dp[On(mask, v - 1)][v] = add(dp[On(mask, v - 1)][v], dp[mask][u]);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n] << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
    solve();
}
