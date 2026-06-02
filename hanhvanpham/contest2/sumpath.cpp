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
int n, m, dp[N][N], dp2[N][N];
char a[N][N];
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
main()
{
    skibidi;
    file("sumpath");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (int)(a[i][j] - '0');
    dp2[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = add(dp[i][j], mul(dp2[i][j] - 1, (int)(a[i][j] - '0')));
            for (int k = 0; k < 3; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                dp2[x][y] = add(dp2[i][j], dp2[x][y]);
                if (x >= 1 && x <= n && y >= 1 && y <= m)
                {
                    dp[x][y] = add(dp[i][j], dp[x][y]);
                    //dp[x][y] = add(dp[x][y], mul(dp2[i][j] - 1, (int)(a[x][y] - '0')));
                }
            }
        }
    }
    cout << dp[n][m];
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
