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
const int N = 1e5 + 69;
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
int n, k, a[N], dp[N][26];
int cnt[N];
int cost = 0;
vector<int> vals;
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            vals.push_back(a[i]);
        }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dp[i][j] = 1e18;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[i]] == 0)
            cost++;
        cnt[a[i]]++;
        dp[i][0] = cost * cost;
    }
    for (int j = 1; j < k; j++)
    {

        for (int i = 1; i <= n; i++)
        {
            cost = 0;
            for (int l = 1; l <= i; l++)
                cnt[a[l]] = 0;
            for (int l = i; l >= 1; l--)
            {
                if (cnt[a[l]] == 0)
                    cost++;
                cnt[a[l]]++;
                if (dp[i][j] > dp[l - 1][j - 1] + cost * cost)
                    dp[i][j] = dp[l - 1][j - 1] + cost * cost;
            }
        }
    }
    cout << dp[n][k - 1];
}
main()
{
    skibidi;
    file("CARGO");
    cin >> n >> k;
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
