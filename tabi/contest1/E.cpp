#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout);  \
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
int n, t, dp[N];
void solve()
{
    cin >> n;
    if (n <= 1e6)
        cout << dp[n] << endl;
    else
    {
        cout << (n - 15) / 15 + dp[n % 15 + 15] << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> t;
    dp[0] = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        dp[i] = 1e18;
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i >= 3)
            dp[i] = min(dp[i], dp[i - 3] + 1);
        if (i >= 6)
            dp[i] = min(dp[i], dp[i - 6] + 1);
        if (i >= 10)
            dp[i] = min(dp[i], dp[i - 10] + 1);
        if (i >= 15)
            dp[i] = min(dp[i], dp[i - 15] + 1);
    }
    while (t--)
        solve();
}
