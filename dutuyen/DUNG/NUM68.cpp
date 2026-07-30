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
const int MOD = 9e18 + 7;
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
int n, a[N];
string s;
long long dp[20][2][11];
long long backtrack(int pos, int carry, bool is67)
{
    if (pos == (int)s.size())
        return (carry == 0 && is67);
    if (dp[pos][carry][is67] != -1)
        return dp[pos][carry][is67];
    int res = 0;
    int x = s[s.size() - 1 - pos] - '0';
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            int sum = (i + j + carry) % 10;
            if (sum == x)
            {
                int ncarry = (i + j + carry) / 10;
                bool n67 = is67 | (i == 6 || i == 8 || j == 6 || j == 8);
                res += backtrack(pos + 1, ncarry, n67);
            }
        }
    return dp[pos][carry][is67] = res;
}
long long calc(string str)
{
    s = str;
    return backtrack(0, 0, 0);
}
bool is67(int x)
{
    while (x)
    {
        if (x % 10 == 6 || x % 10 == 8)
            return 1;
        x /= 10;
    }
    return 0;
}
main()
{
    skibidi;
    file("NUM68");
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        int res = calc(to_string(n));
        if (is67(n))
            res -= 2;
        if (n % 2 == 0)
            if (is67(n / 2))
                res = (res + 1) / 2;
            else
                res = res / 2;
        else
            res = res / 2;
        cout << res << endl;
    }
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
