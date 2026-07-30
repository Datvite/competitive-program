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
int n, q, a[N];
struct LCA
{
    static const int LOG = 21;

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
    void init()
    {
        for (int j = 1; j < LOG; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
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
stack<int> st;
map<int, int> mp[N];
int id[N], cnt = 0;
void solve()
{
    LCA lca(N + 5); 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    id[0] = 0;
    lca.depth[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!st.empty() && st.top() == a[i])
        {
            st.pop();
            id[i] = lca.up[id[i - 1]][0];
        }
        else
        {
            st.push(a[i]);
            auto it = mp[id[i - 1]].find(a[i]);
            if (it != mp[id[i - 1]].end())
            {
                id[i] = it->second;
            }
            else
            {
                id[i] = ++cnt;
                mp[id[i - 1]][a[i]] = id[i];
                lca.up[id[i]][0] = id[i - 1];
                lca.depth[id[i]] = lca.depth[id[i - 1]] + 1;
            }
        }
    }
    lca.n = cnt; 
    lca.init();
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca.dist(id[u - 1], id[v]) << endl;
    }
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
