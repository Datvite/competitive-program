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
int t, n, a[N], col[N], lk[N];
vector<int> g[N];
void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v != par)
        {
            col[v] = 1 ^ col[u];
            dfs(v, u);
        }
    }
}
vector<ii> ans;
void reset()
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        col[i] = 0;
        lk[i] = 0;
    }
    ans.clear();
}
void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        lk[u]++;
        lk[v]++;
    }
    queue<int> q;
    col[1] = 1;
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (lk[i] == 1)
            q.push(i);
    }
    int cur = 1;
    while (!q.empty())
    {
        if (col[q.front()] == cur)
        {
            ans.push_back({1, -1});
            cur = cur ^ 1;
            ans.push_back({2, q.front()});
            for (auto v : g[q.front()])
            {
                lk[v]--;
                // cout << v << " " << lk[v] << endl;
                if (lk[v] == 1)
                    q.push(v);
            }
        }
        else if (col[q.front()] != cur)
        {
            ans.push_back({1, -1});
            cur = cur ^ 1;
            ans.push_back({1, -1});
            cur = cur ^ 1;
            ans.push_back({2, q.front()});
            for (auto v : g[q.front()])
            {
                lk[v]--;
                // cout << v << " " << lk[v] << endl;
                if (lk[v] == 1)
                    q.push(v);
            }
        }
        q.pop();
    }
    ans.push_back({1, -1});
    cout << ans.size() << endl;
    for (auto x : ans)
        if (x.fi == 1)
            cout << x.fi << endl;
        else if (x.fi != n)
            cout << x.fi << " " << x.se << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
