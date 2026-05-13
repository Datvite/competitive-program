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
int n, a[N], m;
int query[N], res = 0;
int ans[N];
struct DSU
{
    vector<int> par, sz, val;
    int maxn = 0;
    DSU(int n)
    {
        par.resize(n + 7);
        sz.resize(n + 7, 1);
        val.resize(n + 7);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            val[i] = a[i];
        }
    }

    int acs(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = acs(par[x]);
    }

    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        val[u] += val[v];
        res = max(res, val[u]);
    }
};
bool rm[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> query[i];
        rm[query[i]] = 1;
    }
    DSU dsu(n);
    res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!rm[i])
        {
            dsu.val[i] = a[i];
            res = max(res, dsu.val[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!rm[i])
        {
            if (i > 1 && !rm[i - 1])
                dsu.join(i, i - 1);
        }
    }
    for (int i = m; i >= 1; i--)
    {
        ans[i] = res;
        int u = query[i];
        rm[u] = 0;
        dsu.val[u] = a[u];
        res = max(res, dsu.val[u]);
        if (u > 1 && !rm[u - 1])
            dsu.join(u, u - 1);
        if (u < n && !rm[u + 1])
            dsu.join(u, u + 1);
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}
main()
{
    skibidi;
    file("RSEQ");
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
