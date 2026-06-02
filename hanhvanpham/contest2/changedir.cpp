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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 3000;
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
int dx[] = {1, 2, 1, 1, 0};
int dy[] = {0, 1, 1, 2, 1};
int q, n, m;
char a[3000][3000];
int dp[3000][3000][6];
main()
{
    skibidi;
    file("changedir");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    if (a[1][1] != '.' || a[n][m] != '.')
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int l = 0; l < 5; l++)
    {
        int nx = 1 + dx[l];
        int ny = 1 + dy[l];
        if (nx <= n && ny <= m && a[nx][ny] == '.')
            dp[nx][ny][l] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != '.')
                continue;
            for (int k = 0; k < 5; k++)
            {
                if (dp[i][j][k] == 0)
                    continue;
                for (int l = 0; l < 5; l++)
                {
                    if (l == k)
                        continue;
                    int nx = i + dx[l];
                    int ny = j + dy[l];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
                        dp[nx][ny][l] = add(dp[nx][ny][l], dp[i][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 5; j++)
        ans = add(ans, dp[n][m][j]);
    cout << ans << endl;
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
