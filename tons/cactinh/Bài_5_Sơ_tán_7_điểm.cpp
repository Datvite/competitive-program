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
const int N = 2e5 + 69;
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
int n, m, a[N], dist[N];
struct edge
{
    int v, w, t;
};
vector<edge> adj[N];
int run(int limit)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();

        if (u == n)
            break;
        if (du != dist[u])
            continue;
        for (auto [v, w, t] : adj[u])
        {
            if (w <= limit && dist[v] > dist[u] + t)
            {
                dist[v] = dist[u] + t;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n];
}
int vis[N];
int cur = 0;
bool check(int limit)
{
    cur++;
    queue<int> q;
    q.push(1);
    vis[1] = cur;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == n)
            return 1;
        for (auto [v, w, t] : adj[u])
        {
            if (w <= limit && vis[v] != cur)
            {
                vis[v] = cur;
                q.push(v);
            }
        }
    }
    return 0;
}
vector<int> vals;
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v, w, t;
        cin >> u >> v >> w >> t;
        adj[u].push_back({v, w, t});
        adj[v].push_back({u, w, t});
        vals.push_back(w);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int l = 0, r = vals.size() - 1, answ = 0, anst = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(vals[mid]))
        {
            answ = vals[mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << answ << " " << run(answ);
}
main()
{
    skibidi;
    file("SOTAN");
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
