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
int n, a[N], q;
struct node
{
    int max1, max2, cnt1, cnt2;
};
node tree[4 * N];
node merge(node L, node R)
{
    int v[4] = {L.max1, L.max2, R.max1, R.max2};
    int c[4] = {L.cnt1, L.cnt2, R.cnt1, R.cnt2};
    for (int i = 0; i < 4; i++)
    {
        if (v[i] == -1e9)
            continue;
        for (int j = i + 1; j < 4; j++)
        {
            if (v[i] == v[j])
            {
                c[i] += c[j];
                v[j] = -1e9;
                c[j] = 0;
            }
        }
    }
    int max1 = -1e9, cnt1 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (v[i] > max1)
        {
            max1 = v[i];
            cnt1 = c[i];
        }
    }
    int max2 = -1e9, cnt2 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (v[i] != max1 && v[i] > max2)
        {
            max2 = v[i];
            cnt2 = c[i];
        }
    }
    node res;
    res.max1 = max1;
    res.cnt1 = cnt1;
    res.max2 = max2;
    res.cnt2 = cnt2;
    return res;
}
void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        tree[id].max1 = val;
        tree[id].max2 = -1e9;
        tree[id].cnt1 = 1;
        tree[id].cnt2 = 0;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
}
node get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        node res;
        res.max1 = -1e9;
        res.max2 = -1e9;
        res.cnt1 = 0;
        res.cnt2 = 0;
        return res;
    }
    if (u <= l && r <= v)
    {
        return tree[id];
    }
    int mid = (l + r) >> 1;
    node left = get(id << 1, l, mid, u, v);
    node right = get(id << 1 | 1, mid + 1, r, u, v);
    return merge(left, right);
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            node res = get(1, 1, n, l, r);
            cout << res.cnt2 << endl;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
    solve();
}
