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
int n, m, r, c, a[N][N], maxn = 0, sum[N][N];
bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int cur = 0;
            if (mid >= a[i][j])
                cur = 1;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + cur;
        }
    int tmp = (r * c + 1) / 2;
    for (int i = r; i <= n; i++)
        for (int j = c; j <= m; j++)
        {
            int cnt = sum[i][j] - sum[i - r][j] - sum[i][j - c] + sum[i - r][j - c];
            if (cnt >= tmp)
                return 1;
        }
    return 0;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            maxn = max(maxn, a[i][j]);
        }
    int l = 0, r = maxn, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("MEDIAN");
    cin >> n >> m >> r >> c;
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
