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
int n, a[N];
struct SegmentTree
{
    struct Node
    {
        long long val;
        Node(long long _val)
        {
            val = _val;
        }
        Node()
        {
            val = 0;
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
        res.val = max(a.val, b.val);
        return res;
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            st[id] = Node(-1e18);
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
            st[id].val = max(st[id].val, val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
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
vector<int> vals;
int sz;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    sz = vals.size();
    SegmentTree seg1(sz), seg2(sz), seg3(sz), seg4(sz);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    seg1.build(1, 1, sz);
    seg2.build(1, 1, sz);
    seg3.build(1, 1, sz);
    seg4.build(1, 1, sz);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur0 = max(1LL, seg1.query(1, 1, sz, 1, a[i] - 1).val + 1);
        int cur1 = seg1.query(1, 1, sz, a[i] + 1, sz).val;
        int cur2 = seg2.query(1, 1, sz, a[i] + 1, sz).val;
        int tmp1 = -1;
        if (cur1 >= 2)
            tmp1 = cur1 + 1;
        if (cur2 >= 3)
            tmp1 = max(tmp1, cur2 + 1);
        int cur1d = seg2.query(1, 1, sz, 1, a[i] - 1).val;
        int cur2d = seg3.query(1, 1, sz, 1, a[i] - 1).val;
        int tmp2 = -1;
        if (cur1d >= 3)
            tmp2 = cur1d + 1;
        if (cur2d >= 4)
            tmp2 = max(tmp2, cur2d + 1);
        int cur3 = seg3.query(1, 1, sz, a[i] + 1, sz).val;
        int cur4 = seg4.query(1, 1, sz, a[i] + 1, sz).val;
        int tmp3 = -1;
        if (cur3 >= 4)
            tmp3 = cur3 + 1;
        if (cur4 >= 5)
            tmp3 = max(tmp3, cur4 + 1);
        seg1.update(1, 1, sz, a[i], cur0);
        if (tmp1 != -1)
            seg2.update(1, 1, sz, a[i], tmp1);
        if (tmp2 != -1)
            seg3.update(1, 1, sz, a[i], tmp2);
        if (tmp3 != -1)
            seg4.update(1, 1, sz, a[i], tmp3);
        ans = max(ans, tmp3);
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("M");
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
