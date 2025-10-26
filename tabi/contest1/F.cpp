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
int n, dp[502 * 502];
void solve()
{
    int S = n * (n + 1) / 2;
    dp[0] = 1;
    if (S % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    S /= 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = S; j >= i; j--)
        {
            dp[j] = add(dp[j], dp[j - i]);
        }
    }
    cout << (dp[S] * ((MOD + 1) / 2)) % MOD << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
