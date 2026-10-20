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
const int N = 5e3 + 69;
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
int n, S, a[N];
bool dp[N][N], suf[N][N];
int sum[N][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]]);
        }
    }
    suf[n + 1][0] = 1;
    sum[n + 1][0] = suf[n + 1][0];
    for (int j = 1; j <= S; j++)
        sum[n + 1][j] = sum[n + 1][j - 1] + suf[n + 1][j];
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            suf[i][j] = suf[i + 1][j];
            if (j >= a[i])
                suf[i][j] = max(suf[i][j], suf[i + 1][j - a[i]]);
        }
        sum[i][0] = suf[i][0];
        for (int j = 1; j <= S; j++)
            sum[i][j] = sum[i][j - 1] + suf[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (dp[i - 1][j])
            {
                int r = S - 1 - j;
                int l = S - a[i] - j;
                if (r < 0)
                    continue;
                int sumR = sum[i + 1][r];
                int sumL;
                if (l > 0)
                    sumL = sum[i + 1][l - 1];
                else
                    sumL = 0;
                if (sumR - sumL > 0)
                {
                    cout << i << " ";
                    break;
                }
            }
        }
    }
}
main()
{
    skibidi;
    file("BAI2");
    cin >> n >> S;
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
