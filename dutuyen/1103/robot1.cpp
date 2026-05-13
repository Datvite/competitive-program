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
int n, m, a[N], color[N], fee[N], dist[N];
vector<ii> adj[N];
priority_queue<ii, vector<ii>, greater<ii>> q;
void dijk(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        auto [du, u] = q.top();
        q.pop();
        if (du != dist[u])
            continue;
        for (auto edge : adj[u])
        {
            int v = edge.fi;
            int id = edge.se;
            int sum = 0;
            for (auto edge2 : adj[u])
            {
                int id2 = edge2.se;
                if (color[id2] == color[id] && id2 != id)
                    sum += fee[id2];
            }
            int cost = min(fee[id], sum);
            if (dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                q.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> color[i] >> fee[i];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dijk(1);
    if (dist[n] == 1e18)
        cout << -1;
    else
        cout << dist[n];
}
main()
{
    skibidi;
    file("robot1");
    cin >> n >> m;
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
