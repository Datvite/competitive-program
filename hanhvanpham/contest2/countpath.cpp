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
const int N = 3e3 + 69;
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
int q, n, a[N], dp[N][N];
void solve()
{
    int x, y;
    cin >> x >> y;
    cout << dp[x][y] << " ";
}
main()
{
    skibidi;
    file("countpath");
    cin >> q;
    dp[1][1] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (i != 1)
                dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j != 1)
                dp[i][j] = add(dp[i][j], dp[i][j - 1]);
            if (i != 1 && j != 1)
                dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    while (q--)
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
