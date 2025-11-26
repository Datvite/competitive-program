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
int n, a[N], k, ans = 0;
bool dp[502][502][502];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int x = 0; x <= k; x++)
            for (int y = 0; y <= k; y++)
            {
                if (dp[i][x][y] == 0)
                    continue;
                if (x + a[i + 1] <= k && y + a[i + 1] <= k)
                    dp[i + 1][x + a[i + 1]][y + a[i + 1]] = 1;
                dp[i + 1][x][y] = 1;
                if (y + a[i + 1] <= k)
                    dp[i + 1][x][y + a[i + 1]] = 1;
            }
    for (int i = 0; i <= k; i++)
        if (dp[n][i][k])
            ans++;
    cout << ans << endl;
    for (int i = 0; i <= k; i++)
        if (dp[n][i][k])
            cout << i << " ";
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    solve();
}
