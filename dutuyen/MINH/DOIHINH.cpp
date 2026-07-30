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
const int N = 1e3 + 69;
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
int n, k, a[N][N], sum[N][N], ans = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= n - k + 1; j++)
        {
            int sumd = 0, sumt = 0;
            int x2 = i + k - 1;
            int y2 = j + k - 1;
            for (int l = 0; l < k; l++)
            {
                sumd += sum[x2][j + l] - sum[i + l][j + l] - sum[x2][j - 1 + l] + sum[i + l][j - 1 + l];
                sumt += sum[i + l][y2] - sum[i + l][j + l] - sum[i - 1 + l][y2] + sum[i - 1 + l][j + l];
            }
            //cout << i << " " << j << ": " << sumd << " " << sumt << endl;
            ans = min(ans, abs(sumd - sumt));
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
