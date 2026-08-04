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
int n, a, b, h[N], dp[207][40007][2], sum[N], ans = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        sum[i] = sum[i - 1] + h[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            dp[i][j][0] = 1e18;
            dp[i][j][1] = 1e18;
        }
    }
    if (h[1] <= a)
        dp[1][h[1]][0] = 0;
    if (h[1] <= b)
        dp[1][0][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = a; j >= 0; j--)
        {
            if (j - h[i] >= 0 && dp[i - 1][j - h[i]][0] != 1e18)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - h[i]][0]);

            if (sum[i] - j >= 0 && sum[i] - j <= b && dp[i - 1][j][0] != 1e18)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + min(h[i], h[i - 1]));

            if (j - h[i] >= 0 && dp[i - 1][j - h[i]][1] != 1e18)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - h[i]][1] + min(h[i], h[i - 1]));

            if (sum[i] - j >= 0 && sum[i] - j <= b && dp[i - 1][j][1] != 1e18)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);
        }
    }
    for (int j = 0; j <= a; j++)
        ans = min(ans, min(dp[n][j][0], dp[n][j][1]));
    if (ans == 1e18)
        ans = -1;
    cout << ans;
}
main()
{
    skibidi;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
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
