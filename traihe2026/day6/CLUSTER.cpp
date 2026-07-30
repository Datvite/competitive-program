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
int n, k, a[N], cnt = 0, f[N];
vector<ii> adj[N];
void dfs(int u, int parent, int lim)
{
    vector<int> vec;
    for (auto [v, w] : adj[u])
    {
        if (v != parent)
        {
            dfs(v, u, lim);
            if (f[v] + w <= lim)
                vec.push_back(f[v] + w);
            else
                cnt++;
        }
    }
    sort(all(vec));
    while (vec.size() >= 2)
    {
        if (vec[vec.size() - 1] + vec[vec.size() - 2] > lim)
        {
            vec.pop_back();
            cnt++;
        }
        else
        {
            break;
        }
    }
    f[u] = vec.empty() ? 0 : vec.back();
}
bool check(int lim)
{
    cnt = 1;
    dfs(1, 0, lim);
    return cnt <= k;
}
void solve()
{
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int l = 1, r = 1e18, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
