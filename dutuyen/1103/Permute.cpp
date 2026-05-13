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
int n, q, a[N], mleft[N], res[N];
stack<int> st;
struct BIT
{
    int n;
    vector<int> bit;

    BIT(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void up(int i, int k)
    {
        for (; i <= n; i += i & -i)
        {
            bit[i] += k;
        }
    }

    int get(int i)
    {
        int res = 0;
        for (; i; i -= i & -i)
        {
            res += bit[i];
        }
        return res;
    }

    int query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
vector<ii> que[N];
vector<int> v[N];
void solve()
{
    BIT bit(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        if (st.empty())
            mleft[i] = 0;
        else
            mleft[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
        v[mleft[i]].push_back(i);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        que[l].push_back({r, i});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : v[i - 1])
        {
            bit.up(x, 1);
        }
        for (auto [r, id] : que[i])
        {
            res[id] = bit.query(i, r);
        }
    }
    for (int i = 1; i <= q; i++)
        cout << res[i] << endl;
}
main()
{
    skibidi;
    file("permute");
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
