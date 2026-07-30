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
const int N = 2e3 + 236;
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
int n, a[N], dp[N], trace[N], deg[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        dp[i] = -1e18;
    dp[0] = n * a[1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n - 2; j++)
        {
            if (dp[j] < dp[j - i] + a[i + 1] - a[1])
            {
                dp[j] = dp[j - i] + a[i + 1] - a[1];
                trace[j] = i;
            }
        }
    }
    cout << dp[n - 2] << endl;
    set<int> leaf;
    int id = 1, cur = n - 2;
    while (cur != 0)
    {
        deg[id] = trace[cur] + 1;
        cur -= trace[cur];
        id++;
    }
    while (id <= n)
    {
        deg[id] = 1;
        id++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
            leaf.insert(i);
    }
    vector<ii> adj;
    for (int i = 1; i < n - 1; i++)
    {
        int u = *leaf.begin();
        leaf.erase(leaf.begin());
        int v;
        for (int j = 1; j <= n; j++)
        {
            if (deg[j] > 1)
            {
                v = j;
                break;
            }
        }
        adj.push_back({u, v});
        deg[u]--;
        deg[v]--;
        if (deg[u] == 1)
            leaf.insert(u);
        if (deg[v] == 1)
            leaf.insert(v);
    }
    int u = *leaf.begin();
    leaf.erase(leaf.begin());
    int v = *leaf.begin();
    leaf.erase(leaf.begin());
    adj.push_back({u, v});
    cout << adj.size() << endl;
    for (auto e : adj)
        cout << e.fi << " " << e.se << endl;
}
main()
{
    skibidi;
    file("deggraph");
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
