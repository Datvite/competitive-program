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
int n, v[N], dp[N], w[N], maxv = 0, W;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        maxv += v[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= maxv; i++)
        dp[i] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = maxv; j >= v[i]; j--)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    for (int i = maxv; i >= 0; i--)
    {
        if (dp[i] <= W)
        {
            cout << i << endl;
            return;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> W;
    solve();
}
