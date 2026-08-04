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
int n, a[N], ans = 0;
ii f[(1 << 22)];
void update(int mask, int id)
{
    if (id == f[mask].fi || id == f[mask].se) return;
    if (f[mask].fi < id)
    {
        f[mask].se = f[mask].fi;
        f[mask].fi = id;
    }
    else if (f[mask].se < id)
    {
        f[mask].se = id;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            update(a[i], i);
        }
    for (int i = 0; i < 22; i++)
    {
        for (int mask = (1 << 22) - 1; mask >= 0; mask--)
        {
            if (!(mask & (1 << i)))
            {
                update(mask, f[mask | (1 << i)].fi);
                update(mask, f[mask | (1 << i)].se);
            }
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int mask = 0;
        for (int j = 21; j >= 0; j--)
        {
            if (!(a[i] & (1 << j)))
            {
                if (f[mask | (1 << j)].se > i)
                {
                    mask |= (1 << j);
                }
            }
        }
        ans = max(ans, mask | a[i]);
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
