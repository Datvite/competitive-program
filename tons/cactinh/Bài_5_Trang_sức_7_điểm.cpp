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
const int N = 1e5 + 69;
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
int n, x, y, a[N][8], dp[N][(1 << 7) + 7];
ii b[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(b + 1, b + n + 1, greater<ii>());
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < x; j++)
            cin >> a[i][j];
    for (int i = 0; i <= n; i++)
        for (int mask = 0; mask < (1 << x); mask++)
            dp[i][mask] = -1e18;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << x); mask++)
        {
            int k = i - __builtin_popcount(mask);
            if (k <= y)
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + b[i].fi);
            else
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
            for (int j = 0; j < x; j++)
            {
                if (mask & (1 << j))
                {
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + a[b[i].se][j]);
                }
            }
        }
    }
    cout << dp[n][(1 << x) - 1];
}
main()
{
    skibidi;
    file("BAI5");
    cin >> n >> x >> y;
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
