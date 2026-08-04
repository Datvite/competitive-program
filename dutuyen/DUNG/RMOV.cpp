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
int n, m, k, ans = 0;
void solve()
{
    vector<vector<int>> rev(m + 1, vector<int>(k + 1, 0));
    vector<vector<int>> cur(m + 1, vector<int>(k + 1, 0));
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            for (int l = 1; l <= k; l++)
            {
                cur[j][l] = max(rev[j][l], cur[j - 1][l]);
                cur[j][l] = max({rev[j][l - 1] + a[i][j], cur[j - 1][l - 1] + a[i][j], cur[j][l]});
            }
        }
        rev = cur;
    }
    for (int l = 1; l <= k; l++)
        ans = max(ans, cur[m][l]);
    cout << ans;
}
main()
{
    skibidi;
    file("RMOV");
    cin >> n >> m >> k;
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
