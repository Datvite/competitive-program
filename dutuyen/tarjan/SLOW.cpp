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
int n, a[N], in[N], out[N], cnt = 0;
vector<int> adj[N];
void dfs(int u, int par)
{
    in[u] = out[u] = ++cnt;
    for (int v : adj[u])
    {
        if (v != par)
        {
            dfs(v, u);
            out[u] = max(out[u], out[v]);
        }
    }
}
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
        res.val = a.val + b.val;
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
        int mid = (l + r) >> 1;
        long long t = lazy[id];
        st[id << 1].val += (mid - l + 1) * t;
        lazy[id << 1] += t;
        st[id << 1 | 1].val += (r - mid) * t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            st[id].val += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int pos)
    {
        if (pos < l || r < pos)
            return Node(0);
        if (l == r)
            return st[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, pos), query(id << 1 | 1, mid + 1, r, pos));
    }
};
void solve()
{
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    SegmentTree seg(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << seg.query(1, 1, n, in[x]).val << endl;
        seg.update(1, 1, n, in[x], out[x], 1);
    }
}
main()
{
    skibidi;
    file("SLOW");
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
