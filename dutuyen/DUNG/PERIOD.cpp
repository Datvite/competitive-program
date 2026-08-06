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
const int N = 5e6 + 69;
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
int n, delta, p, q, m, a[N], pre[N], suf[N], ans = 9e18;
void solve()
{
    for (int i = 1; i <= n; i++)
        a[i] = (p * i) % m + q + delta * i;
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], a[i]);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur = max(pre[i] + delta * (n - i), suf[i + 1] - delta * i);
        ans = min(ans, cur);
    }
    cout << ans;
}

main()
{
    skibidi;
    file("PERIOD");
    cin >> n >> delta >> p >> q >> m;
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
