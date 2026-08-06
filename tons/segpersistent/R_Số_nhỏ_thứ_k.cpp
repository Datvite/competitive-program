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
int n, q, a[N];
vector<int> vals;
struct PersistentSeg
{
    struct Node
    {
        int left, right, sum;
        Node() {left = right = sum = 0;}
        Node(int _sum) : left(0), right(0), sum(_sum) {};
    } node[N * 25];
    int numNode = 0, numVer = 0;
    int version[N]; // root cua i
    void merge(int id)
    {
        node[id].sum = node[node[id].left].sum + node[node[id].right].sum;
    }

    int build(int l, int r)
    {
        if (l == r)
        {
            return ++numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        node[id].left = build(l, mid);
        node[id].right = build(mid + 1, r);
        merge(id);
        return id;
    }

    int update(int l, int r, int pos, int oldver)
    {
        if (l == r)
        {
            node[++numNode] = Node(node[oldver].sum + 1);
            return numNode;
        }
        int mid = (l + r) / 2;
        int id = ++numNode;
        if (pos <= mid)
        {
            node[id].left = update(l, mid, pos, node[oldver].left);
            node[id].right = node[oldver].right;
        }
        else
        {
            node[id].left = node[oldver].left;
            node[id].right = update(mid + 1, r, pos, node[oldver].right);
        }
        merge(id);
        return id;
    }

    int walk(int verL, int verR, int l, int r, int k)
    {
        if (l == r)
            return vals[l - 1];
        int mid = (l + r) / 2;
        int leftSum = node[node[verR].left].sum - node[node[verL].left].sum;
        if (k <= leftSum)
            return walk(node[verL].left, node[verR].left, l, mid, k);
        else
            return walk(node[verL].right, node[verR].right, mid + 1, r, k - leftSum);
    }

    void buildTree()
    {
        numVer = 0;
        version[0] = build(1, n);
    }

    void update(int ver, int pos)
    {
        version[++numVer] = update(1, n, pos, version[ver]);
    }

    void copy(int ver)
    {
        version[++numVer] = version[ver];
    }

    int walk(int l, int r, int k)
    {
        return walk(version[l - 1], version[r], 1, n, k);
    }
} seg;
void solve()
{
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            vals.push_back(a[i]);
        }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    for (int i = 1; i <= n; i++)
        seg.update(i - 1, a[i]);
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << seg.walk(l, r, k) << "\n";
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
