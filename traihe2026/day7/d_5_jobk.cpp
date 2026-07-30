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
int n, m, a[N], indeg[N], cnt = 0, dp[N], root, outdeg[N];
vector<int> g[N], adj[N];
priority_queue<ii> dq;
void dfs(int u)
{
    for (auto v : adj[u])
    {
        dp[v] = dp[u] + 1;
        dfs(v);
    }
}
void solve()
{
    for (int i = 1; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        adj[r].push_back(l);
        indeg[r]++;
        outdeg[l]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (outdeg[i] == 0)
            root = i;
    }
    dp[root] = 1;
    dfs(root);
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            dq.push({dp[i], i});
        }
    }
    while (!dq.empty())
    {
        cnt++;
        vector<ii> vec;
        for (int i = 1; i <= m; i++)
        {
            if (!dq.empty())
            {
                int u = dq.top().se;
                dq.pop();
                for (int v : g[u])
                {
                    indeg[v]--;
                    if (indeg[v] == 0)
                    {
                        vec.push_back({dp[v], v});
                    }
                }
            }
        }
        sort(vec.begin(), vec.end());
        for (auto p : vec)
        {
            dq.push(p);
        }
    }
    cout << cnt;
}
main()
{
    skibidi;
    file("");
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
