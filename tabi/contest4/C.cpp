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
const int MOD = 2e9 + 11;
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
int t, n, m, k, sum[501][501], a[501][501], cnt = 0;
string str[501];
void reset()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            sum[i][j] = 0;
            a[i][j] = 0;
        }
    cnt = 0;
}
void solve()
{
    reset();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        str[i] = " " + str[i];
        for (int j = 1; j <= m; j++)
            if (str[i][j] == 'g')
            {
                a[i][j] = 1;
                cnt++;
            }
            else
                a[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
    int minn = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i][j] == '.')
            {
                int x1 = max(1LL, i - (k - 1));
                int y1 = max(1LL, j - (k - 1));
                int x2 = min(n, i + (k - 1));
                int y2 = min(m, j + (k - 1));
                int res = 0;
                res = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                minn = min(minn, res);
            }
        }
    }
    cout << cnt - minn << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
