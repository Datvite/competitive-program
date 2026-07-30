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
int n, q, ans[N];
ii a[N], query[N];
bool active[N];
struct DSU
{
    vector<int> par, sz;
    DSU(int n)
    {
        par.resize(n + 7);
        sz.resize(n + 7, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
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
    }
};
int cal(int x)
{
    return x * (x + 1) / 2;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].fi;
        query[i].se = i;
    }
    DSU dsu(n);
    sort(a + 1, a + n + 1);
    sort(query + 1, query + q + 1);
    int id = 1, sum = 0;
    for (int i = 1; i <= q; i++)
    {
        int limit = query[i].fi;
        while (id <= n && a[id].fi <= limit)
        {
            active[a[id].se] = 1;
            sum += 1;
            if (a[id].se > 1 && active[a[id].se - 1])
            {
                sum -= cal(dsu.sz[dsu.acs(a[id].se - 1)]);
                sum -= cal(dsu.sz[dsu.acs(a[id].se)]);
                dsu.join(a[id].se, a[id].se - 1);
                sum += cal(dsu.sz[dsu.acs(a[id].se)]);
            }
            if (a[id].se < n && active[a[id].se + 1])
            {
                sum -= cal(dsu.sz[dsu.acs(a[id].se + 1)]);
                sum -= cal(dsu.sz[dsu.acs(a[id].se)]);
                dsu.join(a[id].se, a[id].se + 1);
                sum += cal(dsu.sz[dsu.acs(a[id].se)]);
            }
            id++;
        }
        ans[query[i].se] = sum;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
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
