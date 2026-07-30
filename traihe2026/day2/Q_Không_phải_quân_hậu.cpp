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
const int N = 300 + 69;
const int BASE = 256;
const int MOD = 998244353;
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
int n, m, x, hori[N], ver[N], diag1[2 * N], diag2[2 * N];
int cur_dp[N][N], prev_dp[N][N];
void solve()
{
    memset(cur_dp, 0, sizeof cur_dp);
    memset(prev_dp, 0, sizeof prev_dp);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prev_dp[i][j] = 1;
            res = add(res, prev_dp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            hori[i] = add(hori[i], prev_dp[i][j]);
            ver[j] = add(ver[j], prev_dp[i][j]);
            diag1[i - j + m] = add(diag1[i - j + m], prev_dp[i][j]);
            diag2[i + j] = add(diag2[i + j], prev_dp[i][j]);
        }
    }
    for (int layer = 1; layer <= x; layer++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                cur_dp[j][k] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int caldiag1 = i - j + m;
                int caldiag2 = i + j;
                int invalid = add(add(hori[i], ver[j]), add(diag1[caldiag1], diag2[caldiag2]));
                cur_dp[i][j] = sub(res, invalid);
                cur_dp[i][j] = add(cur_dp[i][j], mul(3, prev_dp[i][j]));
                cnt = add(cnt, cur_dp[i][j]);
            }
        }
        res = cnt;
        for (int i = 1; i <= n; i++)
            hori[i] = 0;
        for (int j = 1; j <= m; j++)
            ver[j] = 0;
        for (int k = 1; k <= n + m; k++)
        {
            diag1[k] = 0;
            diag2[k] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                prev_dp[i][j] = cur_dp[i][j];
                hori[i] = add(hori[i], prev_dp[i][j]);
                ver[j] = add(ver[j], prev_dp[i][j]);
                diag1[i - j + m] = add(diag1[i - j + m], prev_dp[i][j]);
                diag2[i + j] = add(diag2[i + j], prev_dp[i][j]);
            }
        }
    }
    cout << res << endl;
}
main()
{
    skibidi;
    file("antiqueen");
    cin >> n >> m >> x;
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
