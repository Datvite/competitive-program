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
const int MOD = 1e9;
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
int n, a[N], f[4][N], tree[4 * N], k, ans = 0;
vector<int> v;
void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        tree[id] = add(tree[id], val);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            v.push_back(a[i]);
        }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; i++)
        f[1][i] = 1;
    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = get(1, 1, n, a[j] + 1, n);
            update(1, 1, n, a[j], f[i - 1][j]);
        }
        for (int j = 1; j <= 4 * n; j++)
            tree[j] = 0;
    }
    for (int i = 1; i <= n; i++)
        ans += f[k][i];
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    k = 3;
    solve();
}