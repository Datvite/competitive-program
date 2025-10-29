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
#define endl "\n"
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;
const int N = 1e6 + 69;
ll a[N], n;
double f[N];
vector<iii> g[N];
void DFS(int u, int cha)
{
    for (auto e : g[u])
    {
        ll v = e.fi;
        ll t = e.se.se, w = e.se.fi / 100;
        if (v != cha)
        {
            DFS(v, u);
            if (t == 0)
                f[u] = max(f[u], f[v] / w);
            else
                f[u] = max(f[u], (f[v] / w) / 2);
        }
    }
}
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
            f[i] = a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v, w, t;
        cin >> u >> v >> w >> t;
        g[u].push_back({v, {w, t}});
        // g[u].push_back({u, {w, t}});
    }
    DFS(1, -1);
    for (int i = 1; i <= n; i++)
        cout << f[i] << endl;
}
main()
{
    skibidi;
    // file("ql")
    cin >> n;
    sol();
}