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
const int N = 1e3 + 69;
const int BASE = 256;
const int MOD = 1e9 + 7;
const int INF = 2e15;
int add(int a, int b)
{
    if (a >= INF - b)
        return INF;
    return a + b;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n, m, k, dp[N][N];
string ans;
void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!dp[i][j])
                continue;
            for (int c = 1; c <= 26; c++)
            {
                int ntxmod = (j + c) % m;
                dp[i + 1][ntxmod] = add(dp[i + 1][ntxmod], dp[i][j]);
            }
        }
    }
    if (k == 1)
    {
        cout << "" << endl;
        return;
    }
    int curmod = 0;
    for (int i = 0; i <= n; i++)
    {
        if (curmod == 0)
        {
            if (k == 1)
            {
                cout << ans;
                return;
            }
            k--;
        }
        if (i == n)
            break;
        for (int v = 1; v <= 26; ++v)
        {
            int ntxmod = (curmod + v) % m;
            int ways = 0;
            for (int j = i + 1; j <= n; ++j)
            {
                int tmp = (m - ntxmod) % m;
                ways = add(ways, dp[j - (i + 1)][tmp]);
            }

            if (k <= ways)
            {
                ans += (char)('a' + v - 1);
                curmod = ntxmod;
                break;
            }
            else
            {
                k -= ways;
            }
        }
    }
    cout << -1;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> k;
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
