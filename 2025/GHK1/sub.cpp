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
int t, n, a[N], sum[N];
void solve()
{
    cin >> n;
    int maxn = -1e18, ans1 = -1e18;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxn = max(maxn, a[i]);
            if (a[i] > 0)
                {
                    if (ans1 == -1e18)
                        ans1 = 0;
                    ans1 += a[i];
                }
            sum[i] = sum[i - 1] + a[i];
        }
    if (ans1 == -1e18)
        ans1 = maxn;
    int minn = 1e18, ans2 = -1e18;
    for (int i = 1; i <= n; i++)
        {
            minn = min(minn, sum[i - 1]);
            ans2 = max(ans2, sum[i] - minn);
        }
    cout << ans1 << " " << ans2 << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while(t--)
    solve();
}
