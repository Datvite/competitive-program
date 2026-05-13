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
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<long long, ii>
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
int n, m, a[N], cnt = 0, res = 0;
int dx[] = {0, 1};
int dy[] = {1, 0};
vector<iii> edges;
struct DSU
{
    vector<int> par, sz;
    stack<tuple<int, int, int, int>> st;
    int maxn = 0;
    DSU(int n)
    {
        maxn = 1;
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }

    int acs(int x)
    {
        while (x != par[x])
            x = par[x];
        return x;
    }

    void join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return;
        cnt++;
        if (sz[u] < sz[v])
            swap(u, v);
        st.push({v, par[v], sz[u], maxn});
        par[v] = u;
        sz[u] += sz[v];
        maxn = max(maxn, sz[u]);
    }

    void rollback(int x)
    {
        while (x--)
        {
            auto [v, old_p, old_sz, mx] = st.top();
            st.pop();
            if (v == -1)
                return;
            int u = par[v];
            par[v] = old_p;
            sz[u] = old_sz;
            maxn = mx;
        }
    }
};
int id(int i, int j)
{
    return (i - 1) * m + j;
}
long long enc(int i, int j)
{
    if (i > j)
        swap(i, j);
    return i * 1e9 + j;
}
void solve()
{
    DSU dsu(n * m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            a[id(i, j)] = x;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int u = i + dx[k];
                int v = j + dy[k];
                if (1 <= u && u <= n && 1 <= v && v <= m && a[id(i, j)] == a[id(u, v)])
                {
                    dsu.join(id(i, j), id(u, v));
                }
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int u = i + dx[k];
                int v = j + dy[k];
                if (1 <= u && u <= n && 1 <= v && v <= m && a[id(i, j)] != a[id(u, v)])
                {
                    edges.push_back({enc(a[id(i, j)], a[id(u, v)]), {id(i, j), id(u, v)}});
                }
            }
        }
    sort(edges.begin(), edges.end());
    //edges.erase(unique(edges.begin(), edges.end()), edges.end());
    res = max(res, dsu.maxn);
    //cout << res;
    for (int i = 0; i < edges.size(); i++)
    {
        int j = i;
        cnt = 0;
        while (j < edges.size() && edges[i].fi == edges[j].fi)
        {
            dsu.join(edges[j].se.fi, edges[j].se.se);
            j++;
        }
        res = max(res, dsu.maxn);
        dsu.rollback(cnt);
        i = j - 1;
    }
    cout << res;
}
main()
{
    skibidi;
    file("COLORING");
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