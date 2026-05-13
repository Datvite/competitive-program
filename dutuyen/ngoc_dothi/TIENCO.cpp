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
int n, m, k, s, t, a[N], dist[N][2];
vector<ii> adj[N];
priority_queue<iii, vector<iii>, greater<iii>> pq;
bool coin[N];
void dijk(int s)
{
    while (!pq.empty())
        pq.pop();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 1; j++)
            dist[i][j] = 1e18;
    dist[s][0] = 0;
    pq.push({0, {s, 0}});
    if (coin[s])
    {
        dist[s][1] = a[s];
        pq.push({a[s], {s, 1}});
    }
    while (!pq.empty())
    {
        int u = pq.top().se.fi;
        int stat = pq.top().se.se;
        int dt = pq.top().fi;
        pq.pop();
        if (dt > dist[u][stat])
            continue;
        if (stat == 0 && coin[u])
        {
            if (dist[u][0] + a[u] < dist[u][1])
            {
                dist[u][1] = dist[u][0] + a[u];
                pq.push({dist[u][1], {u, 1}});
            }
        }
        for (auto e : adj[u])
        {
            int v = e.fi, w = e.se;
            if (stat == 0)
            {
                if (dist[u][stat] + w < dist[v][0])
                {
                    dist[v][0] = dist[u][stat] + w;
                    pq.push({dist[v][0], {v, 0}});
                }
                if (dist[u][stat] + w + a[v] < dist[v][1] && coin[v])
                {
                    dist[v][1] = dist[u][stat] + w + a[v];
                    pq.push({dist[v][1], {v, 1}});
                }
            }
            else
            {
                if (dist[u][stat] + w < dist[v][1])
                {
                    dist[v][1] = dist[u][stat] + w;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
            // debug
            // cout << u << " " << stat << " " << dt << " " << v << " " << dist[v][0] << " " << dist[v][1] << endl;
        }
    }
}
void solve()
{
    for (int i = 1; i <= k; i++)
    {
        int id, val;
        cin >> id >> val;
        a[id] = val;
        coin[id] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijk(s);
    cout << dist[t][1];
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> k;
    cin >> s >> t;
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
