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
#define ll long long
#define int long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define endl "\n"
using namespace std;
const int N = 1e5 + 69;
const int M = log2(N) + 2;
ll n, a[N], q;
int h[N], P[N][M], dist[N];
vector<ii> g[N];

void DFS(int u, int par)
{
    for (auto e : g[u])
    {
        ll v = e.fi, w = e.se;

        if (v != par)
        {
            h[v] = h[u] + 1;
            dist[v] = dist[u] + w;
            P[v][0] = u;
            DFS(v, u);
        }
    }
}
void init()
{
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    int x = h[u] - h[v];
    for (int i = log2(x); i >= 0; i--)
        if (x >= (1 << i))
        {
            u = P[u][i];
            x -= (1 << i);
        }
    if (u == v)
        return u;
    for (int i = log2(h[u]); i >= 0; i--)
        if (P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    return P[u][0];
}

void sol()
{
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    DFS(1, -1);
    init();
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2 * dist[LCA(u, v)] << "\n";
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
    sol();
}