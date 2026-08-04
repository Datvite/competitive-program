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
int n, a[N], f[(1 << 21)], ans = 0;
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    for (int i = 0; i < 20; i++)
    {
        for (int mask = (1 << 20); mask >= 0; mask--)
        {
            if (!(mask & (1 << i)))
            {
                f[mask] = add(f[mask], f[mask | (1 << i)]);
            }
        }
    }
    for (int mask = 0; mask < (1 << 20); mask++)
    {
        int cur = binpow(2, f[mask]);
        int cnt = __builtin_popcount(mask);
        if (cnt & 1)
            ans = sub(ans, cur);
        else
            ans = add(ans, cur);
    }
    cout << ans << endl;
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
