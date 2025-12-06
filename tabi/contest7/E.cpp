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
node merge(node left, node right)
{
    node res;
    if (left.max1 == right.max1)
    {
        res.max1 = left.max1;
        res.cnt1 = left.cnt1 + right.cnt1;
        res.max2 = max(left.max2, right.max2);
        if (left.max2 == right.max2)
            res.cnt2 = left.cnt2 + right.cnt2;
        else if (left.max2 > right.max2)
            res.cnt2 = left.cnt2;
        else
            res.cnt2 = right.cnt2;
    }
    else if (left.max1 > right.max1)
    {
        res.max1 = left.max1;
        res.cnt1 = left.cnt1;
        res.max2 = max(left.max2, right.max1);
        if (left.max2 == right.max1)
            res.cnt2 = left.cnt2 + right.cnt1;
        else if (left.max2 > right.max1)
            res.cnt2 = left.cnt2;
        else
            res.cnt2 = right.cnt1;
    }
    else
    {
        res.max1 = right.max1;
        res.cnt1 = right.cnt1;
        res.max2 = max(right.max2, left.max1);
        if (right.max2 == left.max1)
            res.cnt2 = right.cnt2 + left.cnt1;
        else if (right.max2 > left.max1)
            res.cnt2 = right.cnt2;
        else
            res.cnt2 = left.cnt1;
    }
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
        return { -1e9, -1e9, 0, 0};
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
            ii res1 = get(1, 1, n, l, r, -1e9);
            ii res2 = get(1, 1, n, l, r, res1.fi);
            cout << res2.se << endl;
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
