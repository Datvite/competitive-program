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
int n, a[N], b[N], c[N], dp[N][4];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = max({dp[i - 1][2], dp[i - 1][3]}) + a[i];
        dp[i][2] = max({dp[i - 1][1], dp[i - 1][3]}) + b[i];
        dp[i][3] = max({dp[i - 1][1], dp[i - 1][2]}) + c[i];
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
