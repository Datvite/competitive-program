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
int t, n, m, a[N], color[N], timer = 1, d[N], S = 0, ans = 0, w0 = 0, w1 = 0;
vector<int> adj[N];
bool dp[N];
void reset()
{
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        color[i] = -1;
    }
    for (int i = 0; i <= S; i++)
        dp[i] = 0;
    timer = 1;
    S = 0;
    ans = 0;
}
bool dfs(int u, int c)
{
    color[u] = c;
    if (c == 1)
        w1 += a[u];
    else
        w0 += a[u];
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            if (!dfs(v, 1 - c))
                return 0;
        }
        else if (color[v] == c)
            return 0;
    }
    return 1;
}
void solve()
{
    reset();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            w0 = w1 = 0;
            if (!dfs(i, 0))
            {
                cout << 0 << endl;
                return;
            }
            int diff = abs(w0 - w1);
            if (diff > 0)
                cnt[diff]++;
            timer++;
        }
    }
    dp[0] = 1;
    for (int i = 1; i < timer; i++)
    {
        for (int j = S; j >= d[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - d[i]]);
        }
    }
    vector<int> vals;
    for (auto [val, num] : cnt)
    {
        int k = 1, cur = num;
        while (cur > 0)
        {
            int cur = min(k, cur);
            vals.push_back(val * cur);
            cur -= cur;
            k *= 2;
        }
    }
    for (int i = 0; i <= S; i++)
    {
        if (dp[i])
            ans++;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("TRANSPORT");
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
