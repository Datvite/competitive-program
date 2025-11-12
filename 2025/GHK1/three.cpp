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
int n, a[N], S = 0, sum[N], ans = 0;
map<int, int> mp;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S += a[i];
    }
    if (S % 3 != 0)
    {
        cout << 0;
        return;
    }
    S /= 3;
    int cur = 0;
    for (int i = n; i >= 1; i--)
    {
        cur += a[i];
        if (cur == S)
            sum[i] = 1;
    }
    for (int i = n - 1; i >= 1; i--)
        sum[i] += sum[i + 1];
    cur = 0;
    for (int i = 1; i < n; i++)
    {
        cur += a[i];
        if (cur == S)
            ans += sum[i + 2];
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}