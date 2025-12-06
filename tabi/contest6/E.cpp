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
int t, n, k;
int logic(int n, int k)
{
    if (n == 1)
        return 1;
    if (k <= n / 2)
        return 2 * k;
    int res = logic(n - n / 2, k - n / 2);
    if (n % 2 == 0)
        return 2 * res - 1;
    else
    {
        int cur = (n - n / 2 + res - 2) % (n - n / 2) + 1;
        return 2 * cur - 1;
    }
}
void solve()
{
    cin >> n >> k;
    cout << logic(n, k) << endl;
}
main()
{
    skibidi;
    // file("");
    cin >> t;
    while (t--)
        solve();
}
