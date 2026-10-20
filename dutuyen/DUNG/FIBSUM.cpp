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
const int N = 1e5 + 69;
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
    struct Matrix
    {
        int a[2][2];
        int r, c;
        Matrix()
        {
            memset(a, 0, sizeof(a));
        }
        Matrix(int r, int c, bool is_identity = false) : r(r), c(c)
        {
            memset(a, 0, sizeof(a));
            if (is_identity)
            {
                for (int i = 0; i < min(r, c); i++)
                    a[i][i] = 1;
            }
        }

        Matrix operator*(const Matrix &other) const
        {
            Matrix res(r, other.c);
            for (int i = 0; i < r; i++)
            {
                for (int k = 0; k < c; k++)
                {
                    if (a[i][k] == 0)
                        continue;
                    for (int j = 0; j < other.c; j++)
                    {
                        res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                    }
                }
            }
            return res;
        }

        Matrix power(long long p)
        {
            Matrix res(2, 2, true);
            Matrix base = *this;
            while (p > 0)
            {
                if (p & 1)
                    res = res * base;
                base = base * base;
                p >>= 1;
            }
            return res;
        }
    };
    struct Node
    {
        Matrix sum;
        Node() 
        {
            sum = Matrix(2, 2);
        }
        Node(Matrix m) 
        {
            sum = m;
        }
    };
    int n;
    vector<Node> st;
    vector<Matrix> lazy;
    vector<bool> check;
    SegmentTree(int _n = 0)
    {
        n = _n;
        st.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, Matrix(2, 2, 1));
        check.assign(4 * n + 5, false);
    }

    Node merge(Node a, Node b)
    {
        Node res;
        res.sum.a[0][0] = (a.sum.a[0][0] + b.sum.a[0][0]) % MOD;
        res.sum.a[0][1] = (a.sum.a[0][1] + b.sum.a[0][1]) % MOD;
        res.sum.a[1][0] = (a.sum.a[1][0] + b.sum.a[1][0]) % MOD;
        res.sum.a[1][1] = (a.sum.a[1][1] + b.sum.a[1][1]) % MOD;
        return res;
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            st[id] = Node(Matrix(2, 2));
            st[id].sum.a[0][0] = 1;
            st[id].sum.a[0][1] = 1;
            st[id].sum.a[1][0] = 1;
            st[id].sum.a[1][1] = 0;
            st[id].sum = st[id].sum.power(a[l] - 1);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    void down(int id)
    {
        if (check[id])
        {
            st[id << 1].sum = st[id << 1].sum * lazy[id];
            st[id << 1 | 1].sum = st[id << 1 | 1].sum * lazy[id];
            lazy[id << 1] = lazy[id << 1] * lazy[id];
            lazy[id << 1 | 1] = lazy[id << 1 | 1] * lazy[id];
            check[id << 1] = 1;
            check[id << 1 | 1] = 1;
            lazy[id] = Matrix(2, 2, 1);
            check[id] = 0;
        }
    }

    void update(int id, int l, int r, int u, int v, long long val)
    {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v)
        {
            Matrix cur(2, 2);
            cur.a[0][0] = 1;
            cur.a[0][1] = 1;
            cur.a[1][0] = 1;
            cur.a[1][1] = 0;
            cur = cur.power(val);
            st[id].sum = st[id].sum * cur;
            lazy[id] = lazy[id] * cur;
            check[id] = 1;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
            return Node(Matrix(2, 2));
        if (u <= l && r <= v)
            return st[id];
        down(id);
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
    }
};
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree tree(n);
    tree.build(1, 1, n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, val;
            cin >> x >> val;
            tree.update(1, 1, n, x, x, val);
        }
        else if (t == 2)
        {
            int l, r, val;
            cin >> l >> r >> val;
            tree.update(1, 1, n, l, r, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            SegmentTree::Node ans = tree.query(1, 1, n, l, r);
            cout << ans.sum.a[0][0] << endl;
        }
    }
}
main()
{
    skibidi;
    file("FIBSUM");
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
