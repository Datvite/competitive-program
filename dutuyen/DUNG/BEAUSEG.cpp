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
int n, k, d, a[N], ans = 0;
void backtrack(int id, int sum, int last)
{
    if (id > k)
    {
        if (sum == n)
            ans++;
        return;
    }
    for (int i = 1; i <= d; i++)
    {
        int cur = last + i;
        if (sum + cur > n)
            break;
        backtrack(id + 1, sum + cur, cur);
    }
}
int dp[207][207][207];
int f(int id, int sum, int last)
{
    if (id > k)
    {
        if (sum == n)
            return 1;
    }
    if (dp[id][sum][last] != -1)
        return dp[id][sum][last];
    int res = 0;
    for (int i = 1; i <= d; i++)
    {
        int cur = last + i;
        if (sum + cur > n)
            break;
        res = add(res, f(id + 1, sum + cur, cur));
    }
    return dp[id][sum][last] = res;
}
void solve()
{
    backtrack(1, 0, 0);
    cout << ans % MOD << endl;
}
void sub2()
{
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0, 0) % MOD << endl;
}
signed main()
{
    skibidi;
    file("BEAUSEQ");
    cin >> n >> k >> d;
    if (n <= 10 && k <= 10 && d <= 10)
        solve();
    else if (n <= 200 && k <= 200 && d <= 200)
        sub2();
    else
        cout << 0 << endl;
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
