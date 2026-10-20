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
        long long val, id;
        Node(long long _val, int _id)
        {
            val = _val;
            id = _id;
        }
        Node()
        {
            val = 0;
            id = -1;
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
        if (a.val > b.val)
        {
            res.val = a.val;
            res.id = a.id;
        }
        else
        {
            res.val = b.val;
            res.id = b.id;
        }
        return res;
    }

    void update(int id, int l, int r, int pos, long long val, int idv)
    {
        if (l == r)
        {
            st[id] = Node(val, idv);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(id << 1, l, mid, pos, val, idv);
        else
            update(id << 1 | 1, mid + 1, r, pos, val, idv);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(0, -1);
        if (u <= l && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
int trace[N], dp[N], ans = 0, root = 0, pos[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    SegmentTree seg(n);
    for (int i = 1; i <= n; i++)
        trace[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        SegmentTree::Node tmp = seg.query(1, 1, n, 1, pos[i] - 1);
        dp[i] = tmp.val + 1;
        trace[i] = tmp.id;
        seg.update(1, 1, n, pos[i], dp[i], i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            root = i;
        }
    }
    cout << ans << endl;
    vector<int> res;
    while (root != -1)
    {
        res.push_back(root);
        root = trace[root];
    }
    sort(all(res));
    for (int x : res)
        cout << x << " ";
    cout << endl;
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
