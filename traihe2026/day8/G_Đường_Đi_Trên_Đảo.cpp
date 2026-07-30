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
int n, m, q, S = 0;
char ch[N][N];
bool vis[N][N];
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
int id(int x, int y)
{
    return x * (n - 1) + y;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ch[i][j];
        }
    }
    LCA lca(n * n + 7);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (ch[i][j] == '#')
            {
                if (S == 0)
                    S = id(i, j);
                if (ch[i][j + 1] == '#')
                {
                    lca.add_edge(id(i, j), id(i, j + 1));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (ch[j][i] == '#')
            {
                if (ch[j + 1][i] == '#')
                {
                    lca.add_edge(id(j, i), id(j + 1, i));
                }
            }
        }
    }
    lca.build(S);
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << lca.dist(id(x1, y1), id(x2, y2)) << endl;
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
