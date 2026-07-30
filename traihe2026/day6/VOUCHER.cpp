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
int n, m, q, to[N], id[N], w[N], ans[N], tin[N], tout[N], timer = 0, u[N], v[N], total[N], res[N];
struct voucher
{
    int id, s, t, x, y;
    int l, r, ans, silver, lc;
};
voucher query[N];
vector<ii> silver;
struct LCA
{
    static const int LOG = 20;

    int n;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(int _n)
    {
        n = _n;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p)
    {
        up[u][0] = p;
        tin[u] = ++timer;
        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            dfs(v, u);
        }
        tout[u] = timer;
    }

    void build(int root = 1)
    {
        dfs(root, 0);
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int k = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k >> i & 1)
                u = up[u][i];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    int dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
struct BIT
{
    vector<int> bit;
    BIT(int n)
    {
        bit.resize(n + 4, 0);
    }

    void up(int i, int k)
    {
        for (; i <= timer + 1; i += i & -i)
        {
            bit[i] += k;
        }
    }

    int get(int i)
    {
        int res = 0;
        for (; i; i -= i & -i)
        {
            res += bit[i];
        }
        return res;
    }

    int query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
void solve()
{
    LCA lca(n);
    for (int i = 1; i < n; i++)
    {
        cin >> u[i] >> v[i];
        lca.add_edge(u[i], v[i]);
    }
    lca.build();
    BIT bit(timer), bitcnt(timer);
    for (int i = 1; i < n; i++)
    {
        if (lca.depth[u[i]] > lca.depth[v[i]])
            to[i] = u[i];
        else
            to[i] = v[i];
    }
    silver.push_back({0, 0});
    for (int i = 1; i <= m; i++)
    {
        cin >> id[i] >> w[i];
        silver.push_back({w[i], id[i]});
    }
    sort(silver.begin(), silver.end());
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].s >> query[i].t >> query[i].x >> query[i].y;
        query[i].id = i;
        query[i].l = 1;
        query[i].r = m;
        query[i].ans = 0;
        query[i].silver = 0;
        query[i].lc = lca.lca(query[i].s, query[i].t);
    }
    for (int t = 1; t <= m; t++)
    {
        bitcnt.up(tin[to[silver[t].se]], 1);
        bitcnt.up(tout[to[silver[t].se]] + 1, -1);
    }

    for (int j = 1; j <= q; j++)
    {
        int u = query[j].s;
        int v = query[j].t;
        int root = query[j].lc;
        int cnt_u = bitcnt.get(tin[u]);
        int cnt_v = bitcnt.get(tin[v]);
        int cnt_lca = bitcnt.get(tin[root]);
        total[j] = cnt_u + cnt_v - 2 * cnt_lca;
    }

    bool changed = 1;
    vector<vector<int>> qmid(m + 1);
    while (changed)
    {
        changed = 0;
        for (int i = 1; i <= q; i++)
        {
            if (query[i].l <= query[i].r)
            {
                int mid = (query[i].l + query[i].r) >> 1;
                qmid[mid].push_back(i);
                changed = 1;
            }
        }
        fill(bit.bit.begin(), bit.bit.end(), 0);
        fill(bitcnt.bit.begin(), bitcnt.bit.end(), 0);
        for (int t = 1; t <= m; t++)
        {
            bit.up(tin[to[silver[t].se]], silver[t].first);
            bit.up(tout[to[silver[t].se]] + 1, -silver[t].first);
            bitcnt.up(tin[to[silver[t].se]], 1);
            bitcnt.up(tout[to[silver[t].se]] + 1, -1);
            if (qmid[t].empty())
                continue;
            for (auto &idx : qmid[t])
            {
                int u = query[idx].s;
                int v = query[idx].t;
                int root = query[idx].lc;
                int resu = bit.get(tin[u]);
                int resv = bit.get(tin[v]);
                int reslca = bit.get(tin[root]);
                int cntu = bitcnt.get(tin[u]);
                int cntv = bitcnt.get(tin[v]);
                int cntlca = bitcnt.get(tin[root]);
                int cnt = cntu + cntv - 2 * cntlca;
                int sum = resu + resv - 2 * reslca;
                if (sum <= query[idx].y)
                {
                    query[idx].ans = t;
                    query[idx].silver = cnt;
                    query[idx].l = t + 1;
                }
                else
                    query[idx].r = t - 1;
            }
            qmid[t].clear();
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int tot = total[i];
        int silver = query[i].silver;
        int gold = tot - silver;
        int remain = query[i].x - gold;
        if (remain < 0)
            res[i] = -1;
        else
            res[i] = remain;
    }
    for (int i = 1; i <= q; i++)
    {
        cout << res[i] << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> q;
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
