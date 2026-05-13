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
int n, k, m, a[N];
struct DSU
{
    vector<int> par, sz;
    DSU(int n, int m)
    {
        int total = (n + 1) * (m + 1);
        par.resize(total);
        sz.resize(total, 1);
        for (int i = 0; i < total; i++)
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
int id(int i, int j)
{
    return (i - 1) * m + j;
}
vector<pair<char, ii>> res;
void solve()
{
    int x1, y1, x2, y2;
    DSU dsu(n, m);
    char type;
    int i, j;
    for (int t = 1; t <= k; t++)
    {
        cin >> type >> i >> j;
        if (type == 'R')
            dsu.join(id(i, j), id(i, j + 1));
        else
            dsu.join(id(i, j), id(i + 1, j));
    }
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
        {
            int u = id(x, y);
            if (y < m)
            {
                int v = id(x, y + 1);
                if (dsu.acs(u) != dsu.acs(v))
                {
                    dsu.join(u, v);
                    res.push_back({'R', {x, y}});
                }
            }
            if (x < n)
            {
                int v = id(x + 1, y);
                if (dsu.acs(u) != dsu.acs(v))
                {
                    dsu.join(u, v);
                    res.push_back({'D', {x, y}});
                }
            }
        }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x.fi << " " << x.se.fi << " " << x.se.se << "\n";
}
main()
{
    skibidi;
    file("CONNECTION");
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
