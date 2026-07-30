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
int Q, n, a, b, dp[N];
void solve()
{
    for (int q = 1; q <= Q; q++)
    {
        cin >> n >> a >> b;
        dp[1] = 0;
        int k = 1;
        for (int j = 2; j <= n; j++)
        {
            while (k < j - 1 && max(dp[k] + a, dp[j - k] + b) > max(dp[k + 1] + a, dp[j - k - 1] + b))
                k++;
            dp[j] = max(dp[k] + a, dp[j - k] + b);
        }
        cout << dp[n] << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> Q;
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
