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
long long dp[20][2][2][20][20];
long long backtrack(int pos, int tight, int started, int last1, int last2)
{
    if (pos == (int)s.size())
        return 1;
    if (dp[pos][tight][started][last1][last2] != -1)
        return dp[pos][tight][started][last1][last2];
    long long res = 0;
    int lim = tight ? (s[pos] - '0') : 9;
    for (int d = 0; d <= lim; d++)
    {
        int ntight = tight && (d == lim);
        int nstarted = started || (d != 0);
        if (nstarted == 0)
            res += backtrack(pos + 1, ntight, nstarted, last1, last2);
        else
        {
            if (last1 == d || last2 == d)
                continue;
            res += backtrack(pos + 1, ntight, nstarted, last2, d);
        }
    }
    return dp[pos][tight][started][last1][last2] = res;
}

long long calc(string str)
{
    s = str;
    memset(dp, -1, sizeof(dp));
    return backtrack(0, 1, 0, 10, 10);
}
int l, r;
main()
{
    skibidi;
    file("PFNUM");
    cin >> l >> r;
    cout << sub(calc(to_string(r)), calc(to_string(l - 1)));
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
