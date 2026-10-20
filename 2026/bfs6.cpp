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
int n, m, s, t, a[N], cnt = 0, ans = 1e18;
vector<iii> g1, g2;
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
    void init(int n)
    {
        maxn = n;
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
void solve()
{
    DSU dsu(n);
    for (int i = 1; i <= m; i++)
    {
        int c, u, v, w;
        cin >> c >> u >> v >> w;
        if (c == 1)
            g1.push_back({w, {u, v}});
        else
            g2.push_back({w, {u, v}});
    }
    sort(all(g1));
    sort(all(g2));
    for (int i = 0; i < g1.size(); i++)
    {
        int u = g1[i].se.fi, v = g1[i].se.se, w = g1[i].fi;
        dsu.join(u, v);
        if (dsu.acs(s) == dsu.acs(t))
        {
            ans = min(ans, w);
            break;
        }
        cnt = 0;
        for (int j = 0; j < g2.size(); j++)
        {
            int x = g2[j].se.fi, y = g2[j].se.se, z = g2[j].fi;
            dsu.join(x, y);
            if (dsu.acs(s) == dsu.acs(t))
            {
                ans = min(ans, w + z);
                break;
            }
        }
        dsu.rollback(cnt);
    }
    dsu.init(n);
    for (int i = 0; i < g2.size(); i++)
    {
        int x = g2[i].se.fi, y = g2[i].se.se, z = g2[i].fi;
        dsu.join(x, y);
        if (dsu.acs(s) == dsu.acs(t))
        {
            ans = min(ans, z);
            break;
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> s >> t;
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
