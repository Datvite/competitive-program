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
const int N = 1e5 + 69;
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
int n, k, a[N], dp[102][N], pre[102][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int j = 1; j <= k; j++)
        pre[0][j] = 1;
    for (int i = 1; i <= n; i++)
    {
        pre[i][0] = dp[i - 1][0];
        for (int j = 1; j <= k; j++)
            pre[i - 1][j] = add(pre[i - 1][j - 1], dp[i - 1][j]);
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = pre[i - 1][j];
            if (j - a[i] - 1 >= 0)
                dp[i][j] = sub(dp[i][j], pre[i - 1][j - a[i] - 1]);
        }
    }
    cout << dp[n][k] << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    solve();
}
