#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define pb push_back
#define pf push_front
typedef pair<int, int> ii;
#define iii pair<int, pair<int, int>>
#define aint(x) x.begin(), x.end()
#define fi first
#define se second
const int inf = 1e18;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const int base = 311;
#define On(mask, i) (mask | (1LL << i))
#define Off(mask, i) (mask ^ (1LL << i))
inline int mul(int a, int b)
{
    return (a % mod) * (b % mod) % mod;
}
inline int sub(int a, int b)
{
    return ((a - b) % mod + mod) % mod;
}
inline int add(int a, int b)
{
    return ((a % mod + b % mod) % mod + mod) % mod;
}
int n, m, a[N][N], p[N * N], siz[N * N], col[N * N], com, d[N * N], par[N * N], large[N * N], sz[N * N], root[N][N];
inline int H(int i, int j)
{
    return (i - 1) * n + j;
}
int acs(int u)
{
    return p[u] == u ? u : p[u] = acs(p[u]);
}
inline void join(int u, int v)
{
    u = acs(u);
    v = acs(v);
    if (u != v)
    {
        p[v] = u;
        siz[u] += siz[v];
    }
}
vector<int> g[N * N];
vector<int> color;
struct pt
{
    int sz, col;
};
pt comp[N * N];
int dx[] = {1, 0};
int dy[] = {0, 1};
inline ll key(int u, int v)
{
    return u * 10000000 + v;
}
struct SSS
{
    ll key, u, v;
};
vector<SSS> mp;
bool operator==(const SSS &a, const SSS &b)
{
    return a.key == b.key && a.u == b.u && a.v == b.v;
}
int cnt, Max;
inline int sol(int u)
{
    while (u != par[u])
        u = par[u];
    return u;
}
stack<ii> history;
inline void uni(int u, int v)
{
    u = sol(u);
    v = sol(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        history.push({v, par[v]});
        history.push({u, sz[u]});
        history.push({u, large[u]});
        par[v] = u;
        sz[u] += sz[v];
        large[u] += large[v];
        Max = max(Max, large[u]);
        cnt++;
    }
}
inline void rointback(int step)
{
    while (step--)
    {
        auto [u, lar] = history.top();
        history.pop();
        large[u] = lar;
        auto [U, old_sz] = history.top();
        history.pop();
        sz[U] = old_sz;
        auto [v, old_par] = history.top();
        history.pop();
        par[v] = old_par;
    }
}
///////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen("coloring.inp", "r"))
    {
        freopen("coloring.inp", "r", stdin);
        freopen("coloring.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            p[H(i, j)] = H(i, j);
            siz[H(i, j)] = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (1 <= x && x <= m && 1 <= y && y <= n && a[i][j] == a[x][y])
                {
                    join(H(i, j), H(x, y));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cmp = acs(H(i, j));
            if (!d[cmp])
            {
                d[cmp] = ++com;
                par[com] = com;
                large[com] = siz[cmp];
                ans = max(ans, large[com]);
                sz[com] = 1;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            root[i][j] = acs(H(i, j));
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (1 <= x && x <= m && 1 <= y && y <= n && a[i][j] != a[x][y])
                {
                    int u = a[i][j], v = a[x][y];
                    if (u > v)
                        swap(u, v);
                    int v1 = d[root[i][j]], v2 = d[root[x][y]];
                    if (v1 > v2)
                        swap(v1, v2);
                    mp.pb({key(u, v), v1, v2});
                }
            }
        }
    }
    sort(aint(mp), [&](const SSS &x, const SSS &y)
         { return x.key < y.key; });
    mp.erase(unique(aint(mp)), mp.end());
    int j = 0;
    for (int i = 0; i < mp.size(); i++)
    {
        cnt = 0, Max = 0;
        while (mp[j].key == mp[i].key)
        {
            uni(mp[j].u, mp[j].v);
            j++;
        }
        ans = max(ans, Max);
        rointback(cnt);
        i = j - 1;
    }
    cout << ans;
}
