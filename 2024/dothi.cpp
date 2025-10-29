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
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, m, en, res, f[N][2];
vector<ll> adj[N];
vector<ll> ans;
ii trace[N];
void dfs(ll u, ll cha)
{
    for (auto v : adj[u])
    {
        //cout << v << endl;
        if (v != cha)
        {
            dfs(v, u);
            f[u][0] += f[v][1];
            f[u][1] += f[v][0];
            
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(i);
        f[i][1] = v;
    }
    dfs(0, -1);
    cout << max(f[0][1] ,  f[0][0]);
}
main()
{
    skibidi;
    file("CIRCUIT");
    cin >> n;
    solve();
}
