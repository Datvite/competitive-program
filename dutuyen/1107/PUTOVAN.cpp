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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 5e4 + 69;
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
int n, m, a[N];
bool check = 1;
struct BFS
{
    int n;
    vector<vector<int>> adj;
    vector<int> dist;
    BFS(int _n)
    {
        n = _n;
        adj.assign(n + 1, {});
        dist.assign(n + 1, 1e9);
    }
    void reset()
    {
        dist.assign(n + 1, 1e9);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void run(int s)
    {
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (dist[v] == 1e9)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
} bfs(0);
vector<int> ans, k;
void sub13()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
            k.push_back(i);
    }
    if (k.empty())
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        return;
    }
    int root = k[0];
    bfs.reset();
    bfs.run(root);
    vector<int> cand;
    for (int i = 1; i <= n; i++)
    {
        if (bfs.dist[i] == a[root])
            cand.push_back(i);
    }
    if (k.size() >= 2)
    {
        int root2 = k[1];

        bfs.reset();
        bfs.run(root2);
        vector<int> tmp;
        for (int s : cand)
        {
            if (bfs.dist[s] == a[root2])
                tmp.push_back(s);
        }
        cand = tmp;
    }
    for (int s : cand)
    {
        bfs.reset();
        bfs.run(s);
        bool ok = 1;
        for (int x : k)
        {
            if (bfs.dist[x] != a[x])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            ans.push_back(s);
    }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
}
void sub2()
{
    if (a[1] == -1)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        return;
    }
    bfs.reset();
    bfs.run(1);
    for (int i = 1; i <= n; i++)
    {
        if (bfs.dist[i] == a[1])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
}
main()
{
    skibidi;
    file("PUTOVAN");
    cin >> n >> m;
    bfs = BFS(n + 67);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        bfs.addEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1 && i > 1)
            check = 0;
    }
    if (check)
        sub2();
    else
        sub13();
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
