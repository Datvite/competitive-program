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
int n, m, k, yl[N], bl[N], par[N], sz[N], ans1 = 0, ans2 = 0;
int acs(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = acs(par[x]);
}
void join(int x, int y)
{
    x = acs(x);
    y = acs(y);
    if (x != y)
    {
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        bl[x] += bl[y];
        yl[x] += yl[y];
    }
}
void solve()
{
    for (int i = 1; i < N; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= k; i++)
        yl[i] = 1;
    for (int i = k + 1; i <= n; i++)
        bl[i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        join(x, y);
        if (yl[acs(x)] == k && ans1 == 0)
            ans1 = i;
        if (bl[acs(x)] == n - k && ans2 == 0)
            ans2 = i;
    }
    cout << ans1 << " " << ans2 << endl;
}
main()
{
    skibidi;
    file("YG");
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
