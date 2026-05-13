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
int n, m, k, s, t, a[N], dist[N][2];
vector<ii> adj[N], addw[N];
priority_queue<iii, vector<iii>, greater<iii>> pq;
void dijk()
{
    for (int i = 1; i <= n; i++)
        dist[i][0] = dist[i][1] = 1e18;
    dist[s][0] = 0;
    pq.push({0, {s, 0}});
    while (!pq.empty())
    {
        iii top = pq.top();
        pq.pop();
        int u = top.se.fi, ty = top.se.se, d = top.fi;
        if (d > dist[u][ty])
            continue;
        for (ii g : adj[u])
        {
            int v = g.fi, w = g.se;
            if (dist[v][ty] > dist[u][ty] + w)
            {
                dist[v][ty] = dist[u][ty] + w;
                pq.push({dist[v][ty], {v, ty}});
            }
        }
        if (ty == 0)
            for (ii g : addw[u])
            {
                int v = g.fi, w = g.se;
                if (dist[v][1] > dist[u][ty] + w)
                {
                    dist[v][1] = dist[u][ty] + w;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
    }
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addw[u].push_back({v, w});
        addw[v].push_back({u, w});
    }
    dijk();
    int ans = min(dist[t][0], dist[t][1]);
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
}
main()
{
    skibidi;
    file("TRANSNET");
    cin >> n >> m >> k >> s >> t;
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
