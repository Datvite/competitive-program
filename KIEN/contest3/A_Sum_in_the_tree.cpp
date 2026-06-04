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
int n, a[N], s[N], ans = 0;
vector<int> g[N];
int dfs(int u, int par, int cha)
{
    int minn = s[u];
    if (minn == -1)
        minn = 1e18;
    if (s[u] == -1)
    {
        int minv = 1e18;
        for (int v : g[u])
            if (v != par)
                minv = min(minv, s[v]);
        if (minv != 1e18)
            s[u] = minv;
    }
    for (int v : g[u])
    {
        int tmp;
        if (s[u] != -1)
            tmp = s[u];
        else
            tmp = cha;
        if (v != par)
        {   
            int cur = dfs(v, u, tmp);
            if (cur != -1)
                minn = min(minn, cur);
        }
    }
    if (minn < s[u])
    {
        cout << -1;
        exit(0);
    }
    if (s[u] != -1)
        a[u] = s[u] - cha;
    return minn;
}
void solve()
{
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    a[1] = s[1];
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans;
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
