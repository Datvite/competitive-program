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
int n, c[N], d[N], a, b, t;
void solve()
{
    cin >> n >> a >> b;
    int g = __gcd(a, b);
    int maxc = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        maxc = max(maxc, c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int diff = (maxc - c[i]) / g;
        c[i] += diff * g;
    }
    sort(c + 1, c + n + 1);
    int ans = c[n] - c[1];
    for (int i = 1; i < n; i++)
        ans = min(ans, c[i] + g - c[i + 1]);
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
