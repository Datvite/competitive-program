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
const int N = 2e5 + 69;
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
int n, q, a[N], tin[N], tout[N], timer = 0, sum[N], depth[N], h[N], at[N], best, ans[N];
vector<int> adj[N];
struct SegmentTree
{
    struct Node
    {
        long long val, id;
        Node(long long _val, long long _id)
        {
            val = _val;
            id = _id;
        }
        Node()
        {
            val = 0;
            id = 0;
        }
    };
    int n;
    vector<Node> st;
    vector<int> lazy;
    SegmentTree(int _n)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, 0);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        if (a.val < b.val)
        {
            res = a;
        }
        else
        {
            res = b;
        }
        return res;
    }
    void down(int id)
    {
        if (lazy[id])
        {
            st[id << 1].val += lazy[id];
            lazy[id << 1] += lazy[id];
            st[id << 1 | 1].val += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void build(int id, int l, int r)
    {
        if (l == r)
        {
            st[id] = Node(a[l], l);
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
            st[id].val = val;
            st[id].id = l;
            return;
        }
        int mid = (l + r) >> 1;
        down(id);
        if (pos <= mid)
            update(id << 1, l, mid, pos, val);
        else
            update(id << 1 | 1, mid + 1, r, pos, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
    void updaterange(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            st[id].val += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        updaterange(id << 1, l, mid, u, v, val);
        updaterange(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }
    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(1e18, 0);
        if (u <= l && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
SegmentTree seg(0);
void dfs(int u, int parent)
{
    tin[u] = ++timer;
    at[timer] = u;
    for (auto v : adj[u])
    {
        if (v != parent)
            dfs(v, u);
    }
    tout[u] = timer;
}
void cal(int k)
{
    while (seg.st[1].val <= k)
    {
        int pos = seg.st[1].id;
        int u = at[pos];
        best = max(best, sum[u]);
        seg.update(1, 1, n, pos, 1e18);
    }
}
vector<ii> edges;
vector<ii> query[N];
void solve()
{
    for (int i = 2; i <= n; i++)
    {
        int b, v;
        cin >> b >> h[i] >> v;
        adj[b].push_back(i);
        sum[i] = sum[b] + v;
        depth[i] = depth[b] + 1;
        edges.push_back({h[i], i});
    }
    dfs(1, 0);
    sort(all(edges));
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int r, k;
        cin >> r >> k;
        query[k].push_back({r, i});
    }
    for (int i = 1; i <= n; i++)
        a[tin[i]] = depth[i];
    for (int i = 0; i <= 10; i++)
    {
        if (query[i].empty())
            continue;
        sort(all(query[i]));
        seg = SegmentTree(n);
        seg.build(1, 1, n);
        best = 0;
        cal(i);
        int cnt = 0;
        for (auto [r, idx] : query[i])
        {
            while (cnt < edges.size() && edges[cnt].fi <= r)
            {
                int x = edges[cnt].se;
                seg.updaterange(1, 1, n, tin[x], tout[x], -1);
                cnt++;
            }
            cal(i);
            ans[idx] = best;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}
main()
{
    skibidi;
    file("c7");
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
