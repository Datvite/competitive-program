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
int n, m, a[N], d[N], low[N], cnt = 0, tplt = 0;
vector<int> adj[N], ans[N];
bool outstack[N];
stack<int> st;
void tarjan(int u)
{
    d[u] = low[u] = ++cnt;
    st.push(u);
    for (auto v : adj[u])
    {
        if (!outstack[v])
        {
            if (d[v] != 0)
                low[u] = min(low[u], d[v]);
            else
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == d[u])
    {
        int v;
        tplt++;
        do
        {
            v = st.top();
            st.pop();
            outstack[v] = 1;
            ans[tplt].push_back(v);

        } while (u != v);
    }
}
void solve()
{
    for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
    for (int i = 1; i <= n; i++)
        if (!d[i])
            tarjan(i);
    for (int i = 1; i <= tplt; i++)
    {
        for (int v : ans[i])
            cout << v << " ";
        cout << endl;
    }
}
main()
{
    skibidi;
    file("SCONNECT");
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
