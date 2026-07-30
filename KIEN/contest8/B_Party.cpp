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
int n, m, dp[(1 << 23)], ans = 1e9;
ii trace[(1 << 23)];
int adj[23];
void solve()
{
    if (m == n * (n - 1) / 2)
    {
        cout << 0 << endl;
        return;
    }
    for (int j = 0; j < (1 << n); j++)
        dp[j] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[1 << i] = 0;
        adj[i] |= (1 << i);
    }
    for (int i = 0; i < (1 << n); i++)
        trace[i] = ii(-1, -1);
    for (int mask = 0; mask <= (1 << n) - 1; mask++)
    {
        if (dp[mask] == 1e9)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                int friendi = adj[i];
                if (dp[mask] + 1 < dp[mask | friendi])
                {
                    dp[mask | friendi] = dp[mask] + 1;
                    trace[mask | friendi] = {i, mask};
                }
            }
        }
    }
    int mask = (1 << n) - 1;
    cout << dp[mask] << endl;
    while (trace[mask] != ii(-1, -1))
    {
        cout << trace[mask].fi + 1 << " ";
        mask = trace[mask].se;
    }
    cout << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
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
