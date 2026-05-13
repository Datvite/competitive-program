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
const int N = 3e2 + 69;
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
int n, m, q, j, a[N], dist[N][N], w[N][N];
bool open[N], g[N][N];
vector<int> node;
void adde(int u)
{
    open[u] = 1;
    node.push_back(u);
    for (auto v : node)
    {
        if (g[u][v])
            dist[u][v] = min(dist[u][v], w[u][v]);
        if (g[v][u])
            dist[v][u] = min(dist[v][u], w[v][u]);
    }
    for (auto k : node)
    {
        for (auto v : node)
        {
            if (dist[u][k] != 1e9 && dist[k][v] != 1e9)
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            if (dist[v][k] != 1e9 && dist[k][u] != 1e9)
                dist[v][u] = min(dist[v][u], dist[v][k] + dist[k][u]);
        }
    }
    for (auto i : node)
    {
        if (dist[i][u] == 1e9)
            continue;
        for (auto j : node)
        {
            if (dist[u][j] == 1e9)
                continue;
            dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][j]);
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = w[i][j] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        w[u][v] = min(w[u][v], c);
        g[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    while (q--)
    {
        char ty;
        cin >> ty;
        if (ty == 'X')
        {
            int u;
            cin >> u;
            if (!open[u])
            adde(u);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            if (dist[u][v] == 1e9 || !open[u] || !open[v])
                cout << -1 << endl;
            else
                cout << dist[u][v] << endl;
        }
    }
}
main()
{
    skibidi;
    file("DWLABYR");
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
