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
int n, m, a[N], cnt1 = 0, cnt2 = 0;
struct NREDUCE
{
    int id, u, v;
};
vector<NREDUCE> one, two, three;
bool mark[N];
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
void solve()
{
    DSU dsu1(n);
    DSU dsu2(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        if (t == 3)
            three.push_back({i, u, v});
        if (t == 2)
            two.push_back({i, u, v});
        if (t == 1)
            one.push_back({i, u, v});
    }
    for (auto edge : three)
    {
        int u = edge.u, v = edge.v, id = edge.id;
        if (dsu1.acs(u) != dsu1.acs(v))
        {
            dsu1.join(u, v);
            cnt1++;
            mark[id] = 1;
        }
        if (dsu2.acs(u) != dsu2.acs(v))
        {
            dsu2.join(u, v);
            cnt2++;
            mark[id] = 1;
        }
    }
    for (auto edge : two)
    {
        int u = edge.u, v = edge.v, id = edge.id;
        if (dsu2.acs(u) != dsu2.acs(v))
        {
            dsu2.join(u, v);
            cnt2++;
            mark[id] = 1;
        }
    }
    for (auto edge : one)
    {
        int u = edge.u, v = edge.v, id = edge.id;
        if (dsu1.acs(u) != dsu1.acs(v))
        {
            dsu1.join(u, v);
            cnt1++;
            mark[id] = 1;
        }
    }
    if (cnt1 != n - 1 || cnt2 != n - 1)
        cout << -1;
    else
    {
        int cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            if (!mark[i])
                cnt++;
        }
        cout << cnt << endl;
        for (int i = 1; i <= m; i++)
        {
            if (!mark[i])
                cout << i << endl;
        }
    }
}
main()
{
    skibidi;
    file("NREDUCE");
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
