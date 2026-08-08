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
int n, m, a[N];
struct line
{
    int a, b;
    line(int a, int b) : a(a), b(b) {}
    int cal(int x)
    {
        return a * x + b;
    }
    int slope()
    {
        return a;
    }
};
struct liChao
{
    vector<line> st;
    liChao() {}
    liChao(int _n)
    {
        st.assign(_n * 4, line(0, 0));
    }

    void addline(int id, line li, int l, int r)
    {
        if (l == r)
        {
            if (li.cal(l) > st[id].cal(l))
                st[id] = li;
            return;
        }
        int mid = (l + r) >> 1;
        if (li.cal(mid) > st[id].cal(mid))
            swap(li, st[id]);
        if (li.slope() < st[id].slope())
            addline(id << 1, li, l, mid);
        else
            addline(id << 1 | 1, li, mid + 1, r);
    }

    void update(int id, line li, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v)
        {
            addline(id, li, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, li, l, mid, u, v);
        update(id << 1 | 1, li, mid + 1, r, u, v);
    }

    int get(int id, int l, int r, int pos)
    {
        int res = st[id].cal(pos);
        if (l == r)
        {
            return res;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            res = get(id << 1, l, mid, pos);
        else
            res = get(id << 1 | 1, mid + 1, r, pos);
        return res;
    }
};
void solve()
{
    liChao lich(n);
    for (int i = 1; i <= m; i++)
    {
        int s, e, v, d;
        cin >> s >> e >> v >> d;
        lich.update(1, line(d, v - d * s), 1, n, s, e);
    }
    for (int i = 1; i <= n; i++)
        cout << lich.get(1, 1, n, i) << endl;

}
main()
{
    skibidi;
    file("jewel");
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
