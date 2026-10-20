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
const int N = 400 + 7;
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
int n, q, m, k, t, a[N], dp[N][N];
bool plane[N];
void solve()
{
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        plane[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if (plane[i] && plane[j])
                    dp[i][j] = t;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][k] < 1e18 && dp[k][j] < 1e18)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = min(dp[u][v], w);
            dp[v][u] = min(dp[v][u], w);
            /*for (int i = 1; i <= n; i++)
                dp[i][v] = min(dp[i][v], dp[i][u] + dp[u][v]);
            for (int i = 1; i <= n; i++)
                dp[u][i] = min(dp[u][i], dp[u][v] + dp[v][i]);
            for (int i = 1; i <= n; i++)
                dp[i][u] = min(dp[i][u], dp[i][v] + dp[v][u]);
            for (int i = 1; i <= n; i++)
                dp[i][v] = min(dp[i][v], dp[i][u] + dp[u][v]);*/
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dp[i][j] = min({dp[i][j], dp[i][u] + dp[u][v] + dp[v][j], dp[i][v] + dp[v][u] + dp[u][j]});
        }
        else if (ty == 2)
        {
            int x;
            cin >> x;
            if (plane[x] == 0)
            {
                plane[x] = 1;
                for (int i = 1; i <= n; i++)
                    if (i != x && plane[i])
                    {
                        dp[i][x] = min(dp[i][x], t);
                        dp[x][i] = min(dp[x][i], t);
                    }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dp[i][x] = min(dp[i][x], dp[i][j] + dp[j][x]);
                    dp[x][i] = min(dp[x][i], dp[x][j] + dp[j][i]);
                }
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][j]);
        }
        else
        {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (dp[i][j] < 1e18)
                        ans += dp[i][j];
            cout << ans << endl;
        }
    }
}
main()
{
    skibidi;
    file("TRAFFIC");
    cin >> n >> m >> q >> k >> t;
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
