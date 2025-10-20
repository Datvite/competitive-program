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
const int MOD = 2e9 + 11;
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
int n, t[4 * N], x[4 * N], val[4 * N];
vector<int> v;
ii tree[4 * N];
void update1(int id, int l, int r, int pos, int val)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        tree[id].se += val;
        return;
    }
    int mid = (l + r) / 2;
    update1(id * 2, l, mid, pos, val);
    update1(id * 2 + 1, mid + 1, r, pos, val);
    if (tree[id * 2].se > tree[id * 2 + 1].se)
        tree[id] = tree[id * 2];
    else
        tree[id] = tree[id * 2 + 1];
}
void update2(int id, int l, int r, int pos, int val)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        tree[id].se -= min(val, tree[id].se);
        return;
    }
    int mid = (l + r) / 2;
    update2(id * 2, l, mid, pos, val);
    update2(id * 2 + 1, mid + 1, r, pos, val);
    if (tree[id * 2].se > tree[id * 2 + 1].se)
        tree[id] = tree[id * 2];
    else
        tree[id] = tree[id * 2 + 1];
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        if (t[i] == 1)
        {
            cin >> x[i] >> val[i];
            v.push_back(val[i]);
        }
        else
            if (t[i] == 2)
            {
                cin >> x[i] >> val[i];
                v.push_back(val[i]);
            }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
