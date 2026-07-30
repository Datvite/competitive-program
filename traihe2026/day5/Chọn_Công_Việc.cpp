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
int n, q, w[N], W = 0;
struct Dinic
{
    struct Edge
    {
        int to;
        long long cap, flow, rev;
    };
    int n, s, t;
    vector<std::vector<Edge>> adj;
    vector<int> level, ptr;
    const long long INF = 1e18;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(2 * n + 7);
        level.resize(2 * n + 7);
        ptr.resize(2 * n + 7);
    }
    void add_edge(int from, int to, long long cap)
    {
        adj[from].push_back({to, cap, 0, (long long)adj[to].size()});
        adj[to].push_back({from, 0, 0, (long long)adj[from].size() - 1});
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &edge : adj[v])
            {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1)
                {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed)
    {
        if (pushed == 0 || v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < adj[v].size(); ++cid)
        {
            auto &edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0)
                continue;
            long long push = dfs(tr, std::min(pushed, edge.cap - edge.flow));
            if (push == 0)
                continue;
            edge.flow += push;
            adj[tr][edge.rev].flow -= push;
            return push;
        }
        return 0;
    }

    long long max_flow()
    {
        long long flow = 0;
        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, INF))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};
void solve()
{
    Dinic dinic(n, 0, 2 * n + 1);
    int source = 0, sink = 2 * n + 1;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        dinic.add_edge(x, y, 1e18);
    }
    for (int i = 1; i <= n; i++)
    {
        if (w[i] > 0)
        {
            dinic.add_edge(source, i, w[i]);
            W += w[i];
        }
        if (w[i] < 0)
        {
            dinic.add_edge(i, sink, -w[i]);
        }
    }
    cout << W - dinic.max_flow();
}
main()
{
    skibidi;
    file("");
    cin >> n;
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
