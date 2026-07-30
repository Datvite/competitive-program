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
int n, a[N], trace[N];
__int128_t dp[N];
void backtrack3(int n, char from, char to, char tmp)
{
    if (n == 1)
    {
        cout << from << to << endl;
        return;
    }
    backtrack3(n - 1, from, tmp, to);
    cout << from << to << endl;
    backtrack3(n - 1, tmp, to, from);
}
void backtrack4(int n, char from, char to, char tmp1, char tmp2)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        cout << from << to << endl;
        return;
    }
    int k = trace[n];
    backtrack4(k, from, tmp1, tmp2, to);
    backtrack3(n - k, from, to, tmp2);
    backtrack4(k, tmp1, to, from, tmp2);
}
void print(__int128_t x)
{
    if (x == 0)
        return;
    print(x / 10);
    int digit = (int)(x % 10);
    cout << digit;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e18;
        for (int j = 0; j < i; j++)
        {
            if (i - j >= 36)
                continue;
            if (dp[i] > 2 * dp[j] + (1LL << (i - j)) - 1)
            {
                dp[i] = 2 * dp[j] + (1LL << (i - j)) - 1;
                trace[i] = j;
            }
        }
    }
    print(dp[n]);
    cout << endl;
    backtrack4(n, 'A', 'D', 'B', 'C');
}
main()
{
    skibidi;
    file("");
    cin >> n;
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
