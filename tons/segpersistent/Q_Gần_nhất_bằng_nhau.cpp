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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 5e5 + 69;
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
struct PersistentSeg
{
    struct Node
    {
        int left, right, dist;
        /*Node()
        {
            left = right = 0;
            dist = 1e18;
        }*/
        Node(int _dist = 1e9) : left(0), right(0), dist(_dist) {};
    } node[N * 25];
    int numNode = 0, numVer = 0;
    int version[N]; // root cua i
    void merge(int id)
    {
        node[id].dist = min(node[node[id].left].dist, node[node[id].right].dist);
    }

    int build(int l, int r)
    {
        if (l == r)
        {
            // node[++numNode] = Node(a[l]);
            return ++numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        node[id].left = build(l, mid);
        node[id].right = build(mid + 1, r);
        merge(id);
        return id;
    }

    int update(int l, int r, int pos, int val, int oldver)
    {
        if (l == r)
        {
            node[++numNode] = Node(val);
            return numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        if (pos <= mid)
        {
            node[id].left = update(l, mid, pos, val, node[oldver].left);
            node[id].right = node[oldver].right;
        }
        else
        {
            node[id].left = node[oldver].left;
            node[id].right = update(mid + 1, r, pos, val, node[oldver].right);
        }
        merge(id);
        return id;
    }

    int get(int ver, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return 1e9;
        if (u <= l && r <= v)
            return node[ver].dist;
        int mid = (l + r) / 2;
        return min(get(node[ver].left, l, mid, u, v), get(node[ver].right, mid + 1, r, u, v));
    }

    void buildTree()
    {
        numVer = 0;
        version[0] = build(1, n);
    }

    void update(int ver, int pos, int val)
    {
        version[++numVer] = update(1, n, pos, val, version[ver]);
    }

    void copy(int ver)
    {
        version[++numVer] = version[ver];
    }

    int getmin(int ver, int l, int r)
    {
        return get(version[ver], 1, n, l, r);
    }
} seg;
int last[N];
vector<int> vals;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    seg.buildTree();
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]] > 0)
            seg.update(i - 1, last[a[i]], i - last[a[i]]);
        else
            seg.copy(i - 1);
        last[a[i]] = i;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = seg.getmin(r, l, r);
        if (ans == 1e9)
            cout << -1 << endl;
        else
            cout << ans << endl;
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
