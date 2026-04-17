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
int t, n, dp[N], best[N];
ii a[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
        dp[i] = 1;
        best[i] = 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n;)
    {
        int j = i;
        while (j <= n && a[j].fi == a[i].fi)
            j++;
        for (int k = i; k < j; k++)
        {
            for (int d = 1; d * d <= a[k].se; d++)
            {
                if (a[k].se % d == 0)
                {
                    dp[a[k].se] = max(dp[a[k].se], best[d] + 1);
                    if (d != a[k].se / d)
                    {
                        dp[a[k].se] = max(dp[a[k].se], best[a[k].se / d] + 1);
                    }
                }
            }
        }
        for (int k = i; k < j; k++)
            best[a[k].se] = max(best[a[k].se], dp[a[k].se]);
        i = j;
    }
    cout << *max_element(best + 1, best + n + 1) << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
