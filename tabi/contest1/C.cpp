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
int n, k, a[N], dp[N][102], ans = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] == 0)
    {
        for (int i = 1; i <= k; i++)
            dp[1][i] = 1;
    }
    else
        dp[1][a[1]] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= k; j++)
            {
                if (j > 1)
                    dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
                if (j < k)
                    dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
            }
        }
        else
        {
            int j = a[i];
            if (j > 1)
                dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j < k)
                dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    for (int i = 1; i <= k; i++)
        ans = add(ans, dp[n][i]);
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    solve();
}
