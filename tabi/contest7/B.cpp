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
int t, n, a[N], dp[N][3];
void reset()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 2; j++)
            dp[i][j] = 0;
}
void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i <= n; i++)
            cin >> a[i];
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
        for (int j = 0; j <= 2; j++)
        {
            int cost = a[i] + j;
            for (int k = 0; k <= 2; k++)
            {
                int cost2 = a[i - 1] + k;
                if (cost != cost2)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j);
            }
        }
    }
    int res = 1e18;
    for (int j = 0; j <= 2; j++)
        res = min(res, dp[n][j]);
    cout << res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
    solve();
}
