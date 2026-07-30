#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
using namespace std;

const int N = 1e6 + 69;
int n, m, k, q;
int u[N], v[N], l[N], r[N], lq[N], rq[N];
int demand[N];

struct Dinic
{
    struct Edge
    {
        int to;
        int cap, flow;
        int rev;
    };
    int n, s, t;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;
    const int INF = 1e9;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }
    void clear()
    {
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
    }

    void add_edge(int from, int to, int cap)
    {
        adj[from].push_back({to, cap, 0, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto &edge : adj[curr])
            {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1)
                {
                    level[edge.to] = level[curr] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int curr, int pushed)
    {
        if (pushed == 0 || curr == t)
            return pushed;
        for (int &cid = ptr[curr]; cid < adj[curr].size(); ++cid)
        {
            auto &edge = adj[curr][cid];
            int tr = edge.to;
            if (level[curr] + 1 != level[tr] || edge.cap - edge.flow == 0)
                continue;
            int push = dfs(tr, min(pushed, edge.cap - edge.flow));
            if (push == 0)
                continue;
            edge.flow += push;
            adj[tr][edge.rev].flow -= push;
            return push;
        }
        return 0;
    }

    int max_flow()
    {
        int flow = 0;
        while (bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INF))
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> l[i] >> r[i];
    }
    int source = n + 1, sink = n + 2;
    Dinic dinic(n + 5, source, sink);
    string ans = "";
    ans.reserve(q);
    while (q--)
    {
        for (int i = 1; i <= k; i++)
            cin >> lq[i] >> rq[i];
        dinic.clear();
        fill(demand + 1, demand + n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            int L = (i <= k) ? lq[i] : l[i];
            int R = (i <= k) ? rq[i] : r[i];
            demand[u[i]] -= L;
            demand[v[i]] += L;
            dinic.add_edge(u[i], v[i], R - L);
        }
        int sumd = 0;
        for (int i = 1; i <= n; i++)
        {
            if (demand[i] > 0)
            {
                dinic.add_edge(source, i, demand[i]);
                sumd += demand[i];
            }
            else if (demand[i] < 0)
            {
                dinic.add_edge(i, sink, -demand[i]);
            }
        }

        if (sumd == 0)
        {
            ans += '1';
        }
        else
        {
            if (dinic.max_flow() == sumd)
                ans += '1';
            else
                ans += '0';
        }
    }
    cout << ans << "\n";
}

int main()
{
    skibidi;
    file("CORE");
    cin >> n >> m >> k >> q;
    solve();
    return 0;
}