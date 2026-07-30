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
const int N = 1e2 + 69;
const int BASE = 256;
const int MOD = 1e18 + 7;
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
int n, k, dp[N][N][N / 2][2];
string str;
int hs(int i, int j)
{
    if (str[i] == '(')
        return (str[j] == ')' | str[j] == '?');
    if (str[i] == '[')
        return (str[j] == ']' | str[j] == '?');
    if (str[i] == '{')
        return (str[j] == '}' | str[j] == '?');
    if (str[i] == '?')
    {
        if (str[j] == '?')
            return 3;
        else if (str[j] == ')' || str[j] == ']' || str[j] == '}')
            return 1;
        else
            return 0;
    }
    else 
        return 0;
}
int f(int i, int j, int depth, bool flag)
{
    if (i > j)
        return 1;
    if ((j - i + 1) % 2 != 0)
        return 0;
    if (dp[i][j][depth][flag] != -1)
        return dp[i][j][depth][flag];

    int res = 0;
    
    if (flag)
    {
        for (int t = i + 1; t < j; t++)
            res = add(res, mul(f(i, t, depth, 0), f(t + 1, j, depth, 1)));
    }

    if (hs(i, j) > 0 && depth >= 1)
        res = add(res, mul(f(i + 1, j - 1, depth - 1, 1), hs(i, j)));

    return dp[i][j][depth][flag] = res;
}
void solve()
{
    memset(dp, -1, sizeof dp);
    cout << f(0, n - 1, k, 1) - f(0, n - 1, k - 1, 1);
}
main()
{
    skibidi;
    file("");
    cin >> n >> k >> str;
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
