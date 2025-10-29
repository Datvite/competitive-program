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
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, dp[N][4], w, f[N], ans = 0;
ii a[N];
void sol0()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (1.0 * a[i].fi / a[i].se > 1.0 * a[j].fi / a[j].se)
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}
void sol1()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][2] = 1;
        dp[i][3] = 1;
        for (int j = 1; j < i; j++)
        {
            if (1.0 * a[i].fi / a[i].se > 1.0 * a[j].fi / a[j].se)
            {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                dp[i][3] = max(dp[i][3], dp[j][3] + 1);
            }
            if (1.0 * a[i].se / a[i].fi > 1.0 * a[j].fi / a[j].se)
            {
                dp[i][2] = max(dp[i][2], dp[j][1] + 1);
            }
            if (1.0 * a[i].fi / a[i].se > 1.0 * a[j].se / a[j].fi)
            {
                dp[i][3] = max(dp[i][3], dp[j][2] + 1);
            }
        }
        ans = max(ans, dp[i][1]);
        ans = max(ans, dp[i][2]);
        ans = max(ans, dp[i][3]);
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("FRACTION");
    cin >> n >> w;
    if (w == 0)
        sol0();
    else
    sol1();
}
