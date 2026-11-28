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
int n, m, k, c[N], p[N], mask[N], cost[N], dp[N];
vector<int> adj[N];
void solve()
{
    for (int i = 0; i < k; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for (int j = 0; j < k; j++)
    {
        int bit = 1 << j;
        if (mask[p[j]] & bit)
            continue;
        queue<int> q;
        mask[p[j]] |= bit;
        q.push(p[j]);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (mask[v] & bit)
                    continue;
                mask[v] |= bit;
                q.push(v);
            }
        }
    }
    int full = (1 << k) - 1;
    for (int i = 0; i <= full; i++) cost[i] = 1e18;
    for (int u = 1; u <= n; u++)
        cost[mask[u]] = min(cost[mask[u]], c[u]);
    for (int mask = full; mask >= 0; mask--)
    {
        if (cost[mask] == 1e18)
            continue;
        for (int i = 0; i < k; i++)
        {
            if (mask & (1 << i))
            {
                int sub = mask ^ (1 << i);
                cost[sub] = min(cost[sub], cost[mask]);
            }
        }
    }
    dp[0] = 0;
    for (int mask = 1; mask <= full; mask++)
        dp[mask] = 1e18;
    for (int mask = 1; mask <= full; mask++)
    {
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
        {
            if (cost[sub] != 1e18 && dp[mask ^ sub] != 1e18)
                dp[mask] = min(dp[mask], dp[mask ^ sub] + cost[sub]);
        }
    }
    cout << dp[full] << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k >> m;
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
