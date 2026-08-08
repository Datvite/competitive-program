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
int n, q, a[N];
struct SegmentTree
{
    struct Node
    {
        long long minv, sum, maxv;
        Node(long long _val)
        {
            minv = _val;
            sum = _val;
            maxv = _val;
        }
        Node()
        {
            minv = 1e18;
            sum = 0;
            maxv = -1e18;
        }
    };
    int n;
    vector<int> lazy;
    vector<Node> st;

    SegmentTree(int _n)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, 0);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.minv = min(a.minv, b.minv);
        res.maxv = max(a.maxv, b.maxv);
        return res;
    }
    void down(int id, int l, int r)
    {
        if (lazy[id] != 0)
        {
            int mid = (l + r) >> 1;
            st[id << 1].minv += lazy[id];
            st[id << 1].maxv += lazy[id];
            st[id << 1].sum += lazy[id] * (mid - l + 1);
            lazy[id << 1] += lazy[id];
            st[id << 1 | 1].minv += lazy[id];
            st[id << 1 | 1].maxv += lazy[id];
            st[id << 1 | 1].sum += lazy[id] * (r - mid);
            lazy[id << 1 | 1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void build(int id, int l, int r)
    {
        if (l == r)
        {
            st[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            st[id] = Node(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
    void updateuv(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (st[id].maxv <= val)
            return;
        down(id, l, r);
        if (l == r)
        {
            int sum = st[id].sum, dif = st[id].maxv - val;
            st[id] = Node(min(st[id].maxv, val));
            st[id].sum = sum - dif;
            return;
        }
        int mid = (l + r) >> 1;
        updateuv(id << 1, l, mid, u, v, val);
        updateuv(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
    void updateuvmax(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (st[id].minv >= val)
            return;
        down(id, l, r);
        if (l == r)
        {
            int sum = st[id].sum, dif = val - st[id].minv;
            st[id] = Node(max(st[id].minv, val));
            st[id].sum = sum + dif;
            return;
        }
        int mid = (l + r) >> 1;
        updateuvmax(id << 1, l, mid, u, v, val);
        updateuvmax(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
    void updatesum(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        down(id, l, r);
        if (u <= l && r <= v)
        {
            st[id].minv += val;
            st[id].sum += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        updatesum(id << 1, l, mid, u, v, val);
        updatesum(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node();
        if (u <= l && r <= v)
            return st[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree seg(n);
    seg.build(1, 1, n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 3)
        {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, n, l, r).sum << endl;
        }
        else if (op == 0)
        {
            int l, r, x;
            cin >> l >> r >> x;
            seg.updateuv(1, 1, n, l, r, x);
        }
        else if (op == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            seg.updatesum(1, 1, n, l, r, x);
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            seg.updateuvmax(1, 1, n, l, r, x);
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
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
