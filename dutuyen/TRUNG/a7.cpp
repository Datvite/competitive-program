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
int n, m, k, a[N];
vector<ii> adj[N];
struct Dijkstra
{
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<long long> dist;
    vector<iii> edges;
    Dijkstra(int _n = 0)
    {
        n = _n;

        adj.assign(n + 1, {});
        dist.assign(n + 1, 1e18);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, {v, w}});
    }

    void run(int s)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != dist[u])
                continue;
            for (auto [v, w] : adj[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};
void solve()
{
    Dijkstra dijk(1e5);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dijk.addEdge(u, v, w);
        // adj[v].push_back({u, w});
    }
    dijk.run(1);
    if (dijk.dist[n] < k)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= m; i++)
    {
        int u = dijk.edges[i - 1].fi;
        int v = dijk.edges[i - 1].se.fi;
        int w = dijk.edges[i - 1].se.se;
        if (w == 1)
            cout << min(max(max(dijk.dist[u], dijk.dist[v]), 1LL), k) << endl;
    }
}
main()
{
    skibidi;
    file("a7");
    cin >> n >> m >> k;
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
