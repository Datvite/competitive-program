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
int n, k, a[N], dist[N];
vector<ii> adj[N];
priority_queue<ii, vector<ii>, greater<ii>> pq;
void dijk(int s)
{
    while (!pq.empty()) 
    pq.pop();
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().se;
        int dt = pq.top().fi;
        pq.pop();
        if (dt > dist[u])
        continue;
        for (auto e : adj[u])
        {
            int v = e.fi, w = e.se;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    while (k--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        else
        {
            int s, t;
            cin >> s >> t;
            dijk(s);
            if (dist[t] == 1e18)
                cout << -1 << endl;
            else
                cout << dist[t] << endl;
        }
    }
}
int32_t main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
