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
int t, n, a[N];
int dp[N][2];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = 1e18;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i + 1]);
        if (i + 2 <= n)
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i + 1] + a[i + 2]);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        if (i + 2 <= n)
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
