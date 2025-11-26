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
int tree[4 * N], n, a[N], k, ans = 0, f[N], cnt = 0;
map<int, int> ma;
void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        tree[id] = val;
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
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]] = 1;
    }
    for (auto i : ma)
        ma[i.fi] = ++cnt;
    for (int i = 1; i <= n; i++)
        a[i] = ma[a[i]];
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = get(1, 1, cnt, 1, a[i] - 1) + 1;
        update(1, 1, cnt, a[i], f[a[i]]);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += f[a[i]];
        //cout << f[a[i]] << endl;
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    sol();
}