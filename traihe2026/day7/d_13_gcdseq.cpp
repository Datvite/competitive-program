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
int n, m, a[N], cnt[N], l[N], r[N], x[N];
vector<ii> v[N];
bitset<24> s[N];
vector<int> ad[N], erase[N];
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
struct SegmentTree
{
    struct Node
    {
        long long val;
        Node(){}
        Node(long long _val)
        {
            val = _val;
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
        res.val = __gcd(a.val, b.val);
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
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> x[i];
        ad[l[i]].push_back(x[i]);
        erase[r[i] + 1].push_back(x[i]);
    }
    bitset<24> bit;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
        for (int x : ad[i])
        {
            if (cnt[x] == 0)
                bit[x] = 1;
            cnt[x]++;
        }
        for (int x : erase[i])
        {
            cnt[x]--;
            if (cnt[x] == 0)
                bit[x] = 0;
        }
        s[i] = bit;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 20; j++)
            if (s[i][j])
            {
                a[i] = lcm(a[i], j);
            }
    }
    SegmentTree seg(n);
    seg.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        if (seg.query(1, 1, n, l[i], r[i]).val != x[i])
        {
            cout << "-1" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
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
