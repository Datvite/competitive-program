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
int n, a[N];
vector<int> g[N];
bool vis[N];
struct TarjanSCC
{
    int n, cnt = 0, tplt = 0;
    vector<vector<int>> adj;

    vector<int> d, low, scc, sz;
    vector<bool> outstack;
    stack<int> st;

    TarjanSCC(int _n)
    {
        n = _n;
        adj.resize(n + 1);

        d.assign(n + 1, 0);
        low.assign(n + 1, 0);
        scc.assign(n + 1, 0);
        outstack.assign(n + 1, false);

        sz.resize(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u)
    {
        d[u] = low[u] = ++cnt;
        st.push(u);

        for (auto v : adj[u])
        {
            if (!outstack[v])
            {
                if (d[v] != 0)
                    low[u] = min(low[u], d[v]);
                else
                {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                }
            }
        }

        if (low[u] == d[u])
        {
            int v;
            ++tplt;

            do
            {
                v = st.top();
                st.pop();

                outstack[v] = true;
                scc[v] = tplt;
                sz[tplt]++;
            }
            while (u != v);
        }
    }

    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!d[i])
                dfs(i);
        }
    }
} tj(N);
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (!vis[v])
            dfs(v);
        tj.sz[u] += tj.sz[v];
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        tj.addEdge(i, v);
    }
    tj.build();
    for (int i = 1; i <= n; i++)
    {
        for (auto v : tj.adj[i])
        {
            if (tj.scc[i] != tj.scc[v])
                g[tj.scc[i]].push_back(tj.scc[v]);
        }
    }
    for (int i = 1; i <= tj.tplt; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        cout << tj.sz[tj.scc[i]] << endl;
}
main()
{
    skibidi;
    file("treat");
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
