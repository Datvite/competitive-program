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
long long backtrack(int pos, int tight, int last)
{
    if (pos == (int)s.size())
        return 1;
    if (dp[pos][tight][last] != -1)
        return dp[pos][tight][last];
    int res = 0;
    int lim = tight ? (s[pos] - '0') : 9;
    for (int d = 0; d <= lim; d++)
    {
        int ntight = tight && (d == lim);
        if (last == 1 && d == 3)
            continue;
        res += backtrack(pos + 1, ntight, d);
    }
    return dp[pos][tight][last] = res;
}
long long calc(string str)
{
    s = str;
    return backtrack(0, 1, -1);
}
bool check(string s)
{
    for (int i = 1; i < (int)s.size(); i++)
        if (s[i - 1] == '1' && s[i] == '3')
            return 0;
    return 1;
}
string l, r;
main()
{
    skibidi;
    file("N13");
    while (cin >> l >> r)
    {
        memset(dp, -1, sizeof(dp));
        int lcal = calc(l);
        memset(dp, -1, sizeof(dp));
        int rcal = calc(r);
        cout << add(sub(rcal, lcal), check(l)) << endl;
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
