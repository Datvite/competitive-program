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
int n, q, ans[N];
vector<int> a;
struct SegmentTree
{
    struct Node
    {
        long long val;
        Node(long long _val = 0)
        {
            val = _val;
        }
    };

    int n;
    vector<Node> st;
    vector<long long> lazy;

    SegmentTree(int _n = 0)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, 0);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.val = min(a.val, b.val);
        return res;
    }

    void build(int id, int l, int r, vector<long long> &a)
    {
        if (l == r)
        {
            st[id] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void down(int id, int l, int r)
    {
        if (lazy[id] == 0)
            return;
        long long t = lazy[id];
        st[id << 1].val += t;
        lazy[id << 1] += t;
        st[id << 1 | 1].val += t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            st[id].val += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void kill(int id, int l, int r, int u, int v, int val)
    {
        if (v < l || r < u)
            return;
        if (st[id].val > 0)
            return;
        if (l == r)
        {
            st[id].val = 1e18;
            ans[l] = val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        kill(id << 1, l, mid, u, v, val);
        kill(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
};
void solve()
{
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ans[i] = -1;
    SegmentTree seg(n);
    seg.build(1, 1, n, a);
    seg.kill(1, 1, n, 1, n, 0);
    for (int i = 1; i <= q; i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        seg.update(1, 1, n, l, r, -s);
        seg.kill(1, 1, n, l, r, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        bool check = 0;
        for (int j = i; j <= n; j += i)
        {
            if (ans[j] == -1)
            {
                check = 1;
                break;
            }
            res = max(res, ans[j]);
        }
        if (check)
            cout << -1 << " ";
        else
            cout << res << " ";
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
