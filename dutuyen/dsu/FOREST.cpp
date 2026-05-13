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
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e3 + 69;
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
int dx[] = {0, 1};
int dy[] = {1, 0};
int n, a[N][N], v[N][N], cnt = 0, res = 0;
const double EPS = 1e-12;
vector<pair<double, ii>> edges;
struct DSU
{
    vector<int> par, sz;
    stack<tuple<int, int, int>> st;
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
        st.push({v, par[v], sz[u]});
        par[v] = u;
        sz[u] += sz[v];
    }

    void rollback(int x)
    {
        while (x--)
        {
            auto [v, old_p, old_sz] = st.top();
            st.pop();
            if (v == -1)
                return;
            int u = par[v];
            par[v] = old_p;
            sz[u] = old_sz;
        }
    }
};
int cd(int i, int j)
{
    return (i - 1) * n + j;
}
void solve()
{
    DSU dsu(n * n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= n)
                {
                    long double b1 = a[i][j] - a[x][y];
                    long double b2 = v[i][j] - v[x][y];
                    if (b1 == b2 && b1 == 0)
                        dsu.join(cd(i, j), cd(x, y));
                    else if (b2 != 0 && b1 != 0)
                        edges.push_back({b1 / b2, {cd(i, j), cd(x, y)}});
                }
            }
        }
    sort(edges.begin(), edges.end());
    res = max(res, dsu.maxn);
    for (int i = 0; i < edges.size(); i++)
    {
        int j = i;
        cnt = 0;
        while (j < edges.size() && fabsl(edges[i].fi - edges[j].fi) < EPS)
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
    file("FOREST");
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
