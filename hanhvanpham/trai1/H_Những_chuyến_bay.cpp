#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
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
const int N = 1e5 + 69;
const int INF = 1e18;
int n, m, k;
vector<ii> adj[N];
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> prev(n + 1, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    prev[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();
        int d = top.fi, u = top.se;
        if (d > prev[u])
            continue;
        for (auto e : adj[u])
        {
            int v = e.fi, w = e.se;
            if (prev[v] > prev[u] + w)
            {
                prev[v] = prev[u] + w;
                pq.push({prev[v], v});
            }
        }
    }
    int ans = prev[n];
    vector<int> cur(n + 1);
    for (int used = 1; used <= k; used++)
    {
        fill(cur.begin(), cur.end(), INF);
        for (int u = 1; u <= n; u++)
        {
            if (prev[u] != INF)
            {
                for (auto e : adj[u])
                {
                    int v = e.fi, w = e.se;
                    if (cur[v] > prev[u] - w)
                        cur[v] = prev[u] - w;
                }
            }
        }
        priority_queue<ii, vector<ii>, greater<ii>> pq_layer;
        for (int u = 1; u <= n; u++)
        {
            if (cur[u] != INF)
                pq_layer.push({cur[u], u});
        }
        while (!pq_layer.empty())
        {
            ii top = pq_layer.top();
            pq_layer.pop();
            int d = top.fi, u = top.se;
            if (d > cur[u])
                continue;
            for (auto e : adj[u])
            {
                int v = e.fi, w = e.se;
                if (cur[v] > cur[u] + w)
                {
                    cur[v] = cur[u] + w;
                    pq_layer.push({cur[v], v});
                }
            }
        }
        ans = min(ans, cur[n]);
        swap(prev, cur);
    }
    cout << ans << endl;
}
signed main()
{
    skibidi;
    file("");
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