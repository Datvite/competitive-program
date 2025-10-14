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
int n, a[N], k, sum[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 1, r = 1, ans = 0;
    while (l <= n && r <= n)
    {
        while (r <= n && sum[r] - sum[l - 1] > k)
            l++;
        if (sum[r] - sum[l - 1] <= k)
            ans = max(ans, r - l + 1);
        r++;
    }
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    solve();
}
