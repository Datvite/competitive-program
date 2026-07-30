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
int n, m, c[N], w[N], ans = 0, totals = 0;
bool valid[(1 << 21)], validB[(1 << 21)];
int ban = 0;
int adj[(1 << 21)], sumw[(1 << 21)], dp[(1 << 21)], sumwB[(1 << 21)];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i]--;
    }
    ban |= (1LL << c[1]) | (1LL << c[n]);
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
        totals += w[i];
    }
    int mid = m / 2;
    for (int i = 1; i < n; i++)
    {
        if (c[i] != c[i + 1])
        {
            adj[c[i]] |= (1LL << c[i + 1]);
            adj[c[i + 1]] |= (1LL << c[i]);
        }
        else
            ban |= (1LL << c[i]);
    }
    valid[0] = 1;
    for (int mask = 1; mask < (1 << mid); mask++)
    {
        int u = __builtin_ctz(mask);
        int pre = mask ^ (1LL << u);
        sumw[mask] = sumw[pre] + w[u];
        if (valid[pre] && !(pre & (adj[u] & ((1LL << mid) - 1))))
            valid[mask] = 1;
    }
    memset(dp, -1, sizeof(dp));
    for (int mask = 0; mask < (1 << mid); mask++)
    {
        if (valid[mask] && !(mask & (ban & ((1LL << mid) - 1))))
            dp[mask] = sumw[mask];
    }
    for (int i = 0; i < mid; i++)
    {
        for (int mask = 0; mask < (1 << mid); mask++)
            if (mask & (1LL << i))
            {
                dp[mask] = max(dp[mask], dp[mask ^ (1LL << i)]);
            }
    }
    validB[0] = 1;
    int left = m - mid;
    if (dp[(1LL << mid) - 1] != -1)
        ans = dp[(1LL << mid) - 1];
    for (int mask = 1; mask < (1LL << left); mask++)
    {
        int u = __builtin_ctz(mask);
        int ur = u + mid;
        int pre = mask ^ (1LL << u);
        sumwB[mask] = sumwB[pre] + w[ur];
        int adjB = (adj[ur] >> mid) & ((1LL << left) - 1);
        if (validB[pre] && !(pre & adjB))
        {
            validB[mask] = 1;
            int banB = (ban >> mid) & ((1LL << left) - 1);
            if (!(mask & banB))
            {
                int badA = 0;
                for (int i = 0; i < left; i++)
                {
                    if (mask & (1LL << i))
                        badA |= adj[i + mid] & ((1LL << mid) - 1);
                }
                int nmask = ((1LL << mid) - 1) ^ badA;
                if (dp[nmask] != -1)
                {
                    ans = max(ans, sumwB[mask] + dp[nmask]);
                }
            }
        }
    }
    cout << totals - ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
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
