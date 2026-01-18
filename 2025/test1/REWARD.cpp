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
int n, k, a[N], dp[N][3], ans = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -1e18;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (k == 2)
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + a[i];
        dp[i][2] = dp[i - 1][1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (k == 1)
            ans = max(ans, dp[i][1]);
        else
            ans = max({ans, dp[i][2], dp[i][1]});
    }
    cout << ans;
}
main()
{
    skibidi;
    file("REWARD");
    cin >> n;
    solve();
}
