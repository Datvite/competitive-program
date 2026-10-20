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
const int N = 5e4 + 69;
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
int n, a[N], k;
long double s1[N], s2[N], dp[107][N];
long double cost(int l, int r)
{
    long double S1 = s1[r] - s1[l - 1];
    long double S2 = s2[r] - s2[l - 1];
    return S2 - (S1 * S1) / (r - l + 1);
}
void compute(int id, int l, int r, int opt_l, int opt_r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    int K = -1;
    long double res = 1e18;
    for (int j = opt_l; j <= std::min(mid - 1, opt_r); j++)
    {
        if (dp[id - 1][j] != 1e18)
        {
            long double cur = dp[id - 1][j] + cost(j + 1, mid);
            if (cur < res)
            {
                res = cur;
                K = j;
            }
        }
    }
    dp[id][mid] = res;
    int nxt = (K == -1) ? opt_l : K;
    compute(id, l, mid - 1, opt_l, nxt);
    compute(id, mid + 1, r, nxt, opt_r);
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + a[i] * a[i];
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        compute(i, 1, n, 0, n - 1);
    cout << fixed << setprecision(6) << dp[k][n];
}
signed main()
{
    skibidi;
    file("BUS");
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
