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
const int N = 1e5 + 69;
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

int n, m, s, t, dist[N];
vector<ii> adj[N];
vector<int> radj[N];

void bfs(int t)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    dist[t] = 0;
    queue<int> q;
    q.push(t);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : radj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        radj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(all(adj[i]));

    bfs(t);

    vector<int> edge_path;
    int cur = s;

    while (cur != t)
    {
        int nxt = -1, chosen_edge = -1;
        for (auto [v, id] : adj[cur])
        {
            if (dist[v] == dist[cur] - 1)
            {
                nxt = v;
                chosen_edge = id;
                break;
            }
        }
        if (nxt == -1)
            break;
        edge_path.push_back(chosen_edge);
        cur = nxt;
    }

    for (int id : edge_path)
        cout << id << " ";
    cout << endl;
}

main()
{
    skibidi;
    file("BFS3");
    cin >> n >> m >> s >> t;
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
