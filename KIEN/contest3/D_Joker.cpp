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
int t, n, a[N], dp[N][3];
char ch[N][3];
int check(ii a, ii b, ii c)
{
    return (ch[a.fi][a.se] == 'A') + (ch[b.fi][b.se] == 'A') + (ch[c.fi][c.se] == 'A') >= 2;
}
void reset()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = -1;
}
void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
            cin >> ch[j][i];
    dp[0][0] = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (dp[i][j] == -1)
                continue;
            int val = dp[i][j];
            if (j == 0)
            {
                if (i + 1 <= n)
                    dp[i + 1][2] = max(dp[i + 1][2], val + check({i + 1, 2}, {i + 2, 2}, {i + 1, 1}));
                if (i + 1 <= n)
                    dp[i + 1][1] = max(dp[i + 1][1], val + check({i + 1, 2}, {i + 2, 1}, {i + 1, 1}));
                if (i + 3 <= n)
                    dp[i + 3][0] = max(dp[i + 3][0], val + check({i + 1, 2}, {i + 2, 2}, {i + 3, 2}) + check({i + 1, 1}, {i + 2, 1}, {i + 3, 1}));
            }
            if (j == 1)
            {
                if (i + 3 <= n)
                    dp[i + 3][1] = max(dp[i + 3][1], val + check({i + 1, 2}, {i + 2, 2}, {i + 3, 2}) + check({i + 2, 1}, {i + 3, 1}, {i + 4, 1}));
                if (i + 2 <= n)
                    dp[i + 2][0] = max(dp[i + 2][0], val + check({i + 1, 2}, {i + 2, 2}, {i + 2, 1}));
            }
            if (j == 2)
            {
                if (i + 3 <= n)
                    dp[i + 3][2] = max(dp[i + 3][2], val + check({i + 1, 1}, {i + 2, 1}, {i + 3, 1}) + check({i + 2, 2}, {i + 3, 2}, {i + 4, 2}));
                if (i + 2 <= n)
                    dp[i + 2][0] = max(dp[i + 2][0], val + check({i + 1, 1}, {i + 2, 1}, {i + 2, 2}));
            }
        }
    }
    cout << dp[n][0] << endl;
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
