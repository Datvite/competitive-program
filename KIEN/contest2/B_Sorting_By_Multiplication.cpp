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
int t, n, a[N], f1[N], f2[N];
void reset()
{
    for (int i = 0; i <= n; i++)
    {
        f1[i] = 0;
        f2[i] = 0;
    }
}
void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 1; i--)
    {
        f1[i] = f1[i + 1] + (a[i] >= a[i + 1]);
    }
    for (int i = 2; i <= n; i++)
    {
        f2[i] = f2[i - 1] + (a[i] >= a[i - 1]);
    }
    int ans = min(f1[1], f2[n] + 1);
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, f1[i + 1] + f2[i] + 1);
    }
    cout << ans << endl;
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
