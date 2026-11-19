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
const int N = 2e4 + 69;
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
struct Edge
{
    int to, id;
};
int n, m;
vector<Edge> adj[N];
int num[N], low[N], timer = 0;
int ans[N];
int cnt = 0;
void tarjan(int u, int par)
{
    num[u] = low[u] = ++timer;
    int child = 0;
    int cnt = 0;
    for (auto edge : adj[u])
    {
        int v = edge.to;
        int id = edge.id;
        if (id == par)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            child++;
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u])
                cnt++;
        }
    }
    if (par == 0)
        ans[u] = child - 1;
    else
        ans[u] = cnt;
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            cnt++;
            tarjan(i, 0);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cnt + ans[i] << endl;
}

main()
{
    skibidi;
    file("CKN");
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
