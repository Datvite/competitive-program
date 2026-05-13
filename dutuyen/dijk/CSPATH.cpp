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
int t, n, m, a[N], way[N], dist[N];
vector<ii> adj[N];
priority_queue<ii, vector<ii>, greater<ii>> pq;
void dijk()
{
    for (int i = 1; i <= n; i++)
        {
            dist[i] = 1e18;
            way[i] = 0;
        }
    dist[1] = 0;
    way[1] = 1;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();
        int u = top.se, d = top.fi;
        if (d > dist[u])
            continue;
        for (ii g : adj[u])
        {
            int v = g.fi, w = g.se;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                way[v] = way[u];
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                way[v] = add(way[v], way[u]);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijk();
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e18)
            cout << -1 << " " << way[i] << endl;
        else
            cout << dist[i] << " " << way[i] << endl;
        adj[i].clear();
    }
}
main()
{
    skibidi;
    file("CSPATH");
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
