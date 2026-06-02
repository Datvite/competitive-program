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
int n, m, s, col[N], par[N];
vector<int> g[N];
bool vis[N];
void dfs(int u, int c)
{
    vis[u] = 1;
    col[u] = c;
    for (int v : g[u])
    {
        if (v == s)
            continue;
        if (vis[v])
        {
            if (col[v] == c)
                continue;
            cout << "Possible" << endl;
            vector<int> path;
            for (int e = u; e != -1; e = par[e])
                path.push_back(e);
            reverse(path.begin(), path.end());
            path.push_back(v);
            cout << path.size() << endl;
            for (int x : path)
                cout << x << ' ';
            cout << endl;
            path.clear();
            for (int e = v; e != -1; e = par[e])
                path.push_back(e);
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (int x : path)
                cout << x << ' ';
            exit(0);
        }
        else if (!vis[v])
        {
            par[v] = u;
            dfs(v, c);
        }
    }
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    par[s] = -1;
    for (auto v : g[s])
    {
        if (!vis[v])
        {
            par[v] = s;
            dfs(v, v);
        }
        else
        {
            cout << "Possible" << endl;
            cout << 2 << endl
                 << s << " " << v << endl;
            vector<int> path;
            for (int e = v; e != -1; e = par[e])
                path.push_back(e);
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (int x : path)
                cout << x << ' ';
            exit(0);
        }
    }
    cout << "Impossible" << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> s;
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
