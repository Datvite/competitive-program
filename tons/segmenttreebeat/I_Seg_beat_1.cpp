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
        long long val, sum;
        Node(long long _val)
        {
            val = _val;
            sum = _val;
        }
        Node()
        {
            val = 0;
            sum = 0;
        }
    };
    int n;
    vector<Node> st;

    SegmentTree(int _n)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.sum = a.sum + b.sum;
        res.val = max(a.val, b.val);
        return res;
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
        if (st[id].val < val)
            return;
        if (l == r)
        {
            st[id] = Node(st[id].val % val);
            return;
        }
        int mid = (l + r) >> 1;
        updateuv(id << 1, l, mid, u, v, val);
        updateuv(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(0);
        if (u <= l && r <= v)
            return st[id];
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
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, n, l, r).sum << endl;
        }
        else if (op == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            seg.updateuv(1, 1, n, l, r, x);
        }
        else
        {
            int pos, x;
            cin >> pos >> x;
            seg.update(1, 1, n, pos, x);
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
