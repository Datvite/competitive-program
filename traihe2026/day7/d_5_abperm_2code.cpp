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
int n, a[N], dp[21][(1 << 21)];
void solve()
{
    for (int i = 0; i <= 20; i++)
        dp[i][(1 << 20) - 1] = 1;
    for (int mask = (1 << 20) - 2; mask >= 0; mask--)
        for (int i = 0; i <= 20; i++)
        {
            dp[i][mask] = 0;
            for (int j = 1; j <= 20; j++)
            {
                if (mask & (1 << (j - 1)) == 0 && (__gcd(i, j) == 1 || i == 0))
                    dp[i][mask] += dp[j][mask | (1 << (j - 1))];
            }
        }
    int rank = 0, mask = 0, last = 0;
    for (int k = 0; k < 20; k++)
    {
        int cur = v[k];
        for (int j = 1; j < cur; j++)
        {
            if (mask & (1 << (j - 1)) == 0 && (__gcd(last, j) == 1 || last == 0))
                rank += dp[j][mask | (1 << (j - 1))];
        }
        mask |= (1 << k);
        last = cur;
    }
    int mask = 0, last = 0;
    for (int k = 0; k < 20; k++)
    {
        int cur = v[k];
        for (int j = 1; j < cur; j++)
        {
            int ways = 0;
            if (mask & (1 << (j - 1)) == 0 && (__gcd(last, j) == 1 || last == 0))
                ways = dp[j][mask | (1 << (j - 1))];
            if (rank > ways)
            {
                rank -= ways;
            }
            else
            {
                mask |= (1 << (k - 1));
                last = cur;
                break;
            }
        }
    }
}
main()
{
    skibidi;
    file("");
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
