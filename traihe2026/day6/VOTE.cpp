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
        long long suf, pref, sum, maxn;
        Node()
        {
            suf = pref = sum = maxn = 0;
        }
        Node(long long _suf, long long _pref, long long _sum, long long _maxn)
        {
            suf = _suf;
            pref = _pref;
            sum = _sum;
            maxn = _maxn;
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
        res.suf = max(b.suf, a.suf + b.sum);
        res.pref = max(a.pref, a.sum + b.pref);
        res.sum = a.sum + b.sum;
        res.maxn = max({a.maxn, b.maxn, a.suf + b.pref});
        return res;
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            if (a[l] == 1)
                st[id] = Node(1, 1, 1, 1);
            else
                st[id] = Node(0, 0, -1, 0);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(-1e18, -1e18, 0, -1e18);
        if (u <= l && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
void solve()
{
    string str;
    cin >> str;
    str = ' ' + str;
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == 'X')
            a[i] = 1;
        else
            a[i] = -1;
    }
    SegmentTree seg(n);
    seg.build(1, 1, n);
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        SegmentTree::Node ans = seg.query(1, 1, n, l, r);
        cout << abs(ans.sum - ans.maxn) << endl;
    }
}
main()
{
    skibidi;
    file("");
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