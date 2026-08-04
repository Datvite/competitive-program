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
const int N = 1e2 + 69;
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
int t, n, a[N], b[N], ans = 0, s = 0, dp[N][20007];
void solve()
{
    cin >> n;
    /*if (n <= 1)
    {
        cout << 0 << endl;
        return;
    }*/
    ans = 0, s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i] * a[i];
        s += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        ans += b[i] * b[i];
        s += b[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= 0; j--)
        {
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]])
                dp[i][j] = 1;
            if (j - b[i] >= 0 && dp[i - 1][j - b[i]])
                dp[i][j] = 1;
        }
    }
    int res = 1e18;
    for (int j = 0; j <= s; j++)
    {
        if (dp[n][j])
            res = min(res, j * j + (s - j) * (s - j));
    }
    cout << ans * (n - 2) + res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
