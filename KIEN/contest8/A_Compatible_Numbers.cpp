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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 2e7 + 69;
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
int n, a[N], f[N], maxn = 0;
void solve()
{
    for (int i = 0; i < N; i++)
        f[i] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        f[a[i]] = a[i];
    }
    int lg = log2(maxn);
    for (int i = 0; i <= lg; i++)
    {
        for (int mask = 0; mask <= (1 << (lg + 1)) - 1; mask++)
        {
            if (mask & (1 << i))
            {
                f[mask] = min(f[mask], f[mask ^ (1 << i)]);
            }
        }
    }
    int mask = (1 << (lg + 1)) - 1;
    for (int i = 1; i <= n; i++)
    {
        int nmask = mask ^ a[i];
        if (f[nmask] != 1e9)
            cout << f[nmask] << " ";
        else
            cout << -1 << " ";
    }
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
