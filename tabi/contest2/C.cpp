#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout);  \
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
int n, t, a[N], fact[N];
void solve()
{
    cin >> n;
    int ans = 1e18;
    for (int mask = 0; mask < (1 << 15); mask++)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < 15; i++)
        {
            if (mask & (1 << i))
            {
                cnt++;
                sum += fact[i];
            }
        }
        if (sum > n)
            break;
        int remain = n - sum;
        int res = cnt + __builtin_popcountll(remain);
        ans = min(ans, res);
    }
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i <= 16; i++)
        fact[i] = fact[i - 1] * i;
    while (t--)
        solve();
}
