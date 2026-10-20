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
const int N = 1e6 + 69;
const int Q = 1e3 + 69;
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
int n, a[Q][Q], maxn = 0, ans = 1, cnt = 0, minn = 1e9;
vector<ii> adj[N];
int id(int x, int y)
{
    return (x - 1) * n + y;
}
struct DSU
{
    vector<int> par, sz;
    stack<tuple<int, int, int>> st;
    int maxn = 0;
    DSU(int n)
    {
        maxn = 1;
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }

    int acs(int x)
    {
        while (x != par[x])
            x = par[x];
        return x;
    }

    bool join(int u, int v)
    {
        u = acs(u);
        v = acs(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        st.push({v, par[v], sz[u]});
        par[v] = u;
        sz[u] += sz[v];
        return 1;
    }

    void rollback(int x)
    {
        while (x--)
        {
            auto [v, old_p, old_sz] = st.top();
            st.pop();
            if (v == -1)
                return;
            int u = par[v];
            par[v] = old_p;
            sz[u] = old_sz;
        }
    }
};
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    DSU dsu(n * n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != n)
            {
                adj[abs(a[i][j] - a[i][j + 1])].push_back({id(i, j), id(i, j + 1)});
                maxn = max(maxn, abs(a[i][j] - a[i][j + 1]));
                minn = min(minn, abs(a[i][j] - a[i][j + 1]));
            }
            if (i != n)
            {
                adj[abs(a[i][j] - a[i + 1][j])].push_back({id(i, j), id(i + 1, j)});
                maxn = max(maxn, abs(a[i][j] - a[i + 1][j]));
                minn = min(minn, abs(a[i][j] - a[i + 1][j]));
            }
        }
    }
    for (int i = minn; i <= maxn; i++)
    {
        cnt = 0;
        for (auto [u, v] : adj[i])
        {
            if (dsu.join(u, v))
                cnt++;
            ans = max(ans, dsu.sz[dsu.acs(u)]);
        }
        dsu.rollback(cnt);
    }
    cout << ans << endl;
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
