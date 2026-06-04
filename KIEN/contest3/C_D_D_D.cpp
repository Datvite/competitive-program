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
int t, n, m, l, a[N], sum = 0, maxo = 0, maxe = 0;
bool mark[N];
struct BFS
{
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> dist;
    BFS(int _n)
    {
        n = _n;
        adj.assign(n + 1, {});
        dist.assign(n + 1, vector<int>(2, 1e18));
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void run(int s)
    {
        queue<ii> q;
        q.push({s, 0});
        dist[s][0] = 0;
        while (!q.empty())
        {
            int u = q.front().fi;
            int w = q.front().se;
            q.pop();
            for (auto v : adj[u])
            {
                if (dist[v][1 - w] > dist[u][w] + 1)
                {
                    dist[v][1 - w] = dist[u][w] + 1;
                    q.push({v, 1 - w});
                }
            }
        }
    }
};
void solve()
{
    cin >> n >> m >> l;
    BFS bfs(n);
    sum = 0;
    maxo = 1e18;
    maxe = 1e18;
    for (int i = 1; i <= l; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 1)
            maxo = min(maxo, a[i]);
        else
            maxe = min(maxe, a[i]);
    }
    if (sum % 2 == 1)
    {
        maxe = sum - maxo;
        maxo = sum;
    }
    else
    {
        maxo = sum - maxo;
        maxe = sum;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        bfs.addEdge(u, v);
    }
    bfs.run(1);
    mark[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (bfs.dist[i][0] != 1e18 && bfs.dist[i][0] <= maxe)
            mark[i] = 1;
        if (bfs.dist[i][1] != 1e18 && bfs.dist[i][1] <= maxo)
            mark[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << mark[i];
    cout << endl;
    for (int i = 1; i <= n; i++)
        mark[i] = 0;
}
main()
{
    skibidi;
    file("");
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
