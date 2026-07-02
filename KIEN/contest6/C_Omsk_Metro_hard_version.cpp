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
const int N = 2e5 + 69;
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
int t, q, a[N];
struct node
{
    int pref, suf, sum, maxn, pref2, suf2, minn;
    node()
    {
        sum = 0;
        pref = suf = maxn = 0;
        pref2 = suf2 = minn = 0;
    }
    node(int x)
    {
        sum = x;
        pref = suf = maxn = max(0LL, x);
        pref2 = suf2 = minn = min(0LL, x);
    }
};
node merge(node a, node b)
{
    node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, b.sum + a.suf);
    res.maxn = max({a.maxn, b.maxn, a.suf + b.pref});
    res.pref2 = min(a.pref2, a.sum + b.pref2);
    res.suf2 = min(b.suf2, b.sum + a.suf2);
    res.minn = min({a.minn, b.minn, a.suf2 + b.pref2});
    return res;
}
struct LCA
{
    static const int LOG = 20;

    int n;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<vector<node>> val;
    vector<int> depth;

    LCA(int _n)
    {
        n = _n;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        val.assign(n + 1, vector<node>(LOG));
        depth.assign(n + 1, 0);
    }
    void init(int root)
    {
        depth[root] = 0;
        for (int j = 0; j < LOG; j++)
        {
            up[root][j] = root;
            val[root][j] = node(1);
        }
    }
    void add_node(int u, int v)
    {
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        val[v][0] = node(a[v]);
        for (int j = 1; j < LOG; j++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
            val[v][j] = merge(val[v][j - 1], val[up[v][j - 1]][j - 1]);
        }
    }

    void dfs(int u, int p)
    {
        up[u][0] = p;
        val[u][0] = node(a[u]);
        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
            val[u][i] = merge(val[u][i - 1], val[up[u][i - 1]][i - 1]);
        }

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;

            dfs(v, u);
        }
    }

    void build(int root = 1)
    {
        dfs(root, 0);
    }

    node invert(node a)
    {
        swap(a.pref, a.suf);
        swap(a.pref2, a.suf2);
        return a;
    }

    node get(int u, int v)
    {
        vector<node> left, right;
        if (depth[u] > depth[v])
        {
            int k = depth[u] - depth[v];
            for (int i = LOG - 1; i >= 0; i--)
            {
                if (k >> i & 1)
                {
                    left.push_back(val[u][i]);
                    u = up[u][i];
                }
            }
        }
        else
        {
            int k = depth[v] - depth[u];
            for (int i = LOG - 1; i >= 0; i--)
            {
                if (k >> i & 1)
                {
                    right.push_back(val[v][i]);
                    v = up[v][i];
                }
            }
        }
        if (u == v)
        {
            left.push_back(val[u][0]);
        }
        else
        {
            for (int i = LOG - 1; i >= 0; i--)
            {
                if (up[u][i] != up[v][i])
                {
                    left.push_back(val[u][i]);
                    right.push_back(val[v][i]);
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            left.push_back(val[u][0]);
            right.push_back(val[v][0]);
            left.push_back(val[up[u][0]][0]);
        }
        node resleft;
        if (!left.empty())
        {
            resleft = left[0];
            for (int i = 1; i < left.size(); i++)
                resleft = merge(resleft, left[i]);
        }
        node resright;
        if (!right.empty())
        {
            for (int i = 0; i < right.size(); i++)
                right[i] = invert(right[i]);
            reverse(right.begin(), right.end());
            resright = right[0];
            for (int i = 1; i < right.size(); i++)
                resright = merge(resright, right[i]);
            return merge(resleft, resright);
        }
        return resleft;
    }
};
void solve()
{
    cin >> q;
    LCA lca(q + 6);
    lca.init(1);
    a[1] = 1;
    int cur = 1;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int x, val;
            cin >> x >> val;
            cur++;
            a[cur] = val;
            lca.add_node(x, cur);
        }
        else
        {
            int u, v, k;
            cin >> u >> v >> k;
            node ans = lca.get(u, v);
            if (ans.maxn >= k && ans.minn <= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    for (int i = 1; i <= cur; i++)
        a[i] = 0;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
