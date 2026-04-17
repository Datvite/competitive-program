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
int n, m, a[N], par[N], sz[N], tplt = 0;
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
    }
}
void solve()
{
    for (int i = 1; i < N; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    tplt = n;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (acs(x) != acs(y))
        {
            join(x, y);
            tplt--;
        }
        cout << tplt << endl;
    }
}
main()
{
    skibidi;
    file("DSF");
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
