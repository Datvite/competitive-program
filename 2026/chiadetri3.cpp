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
int n, a[N], ans = 0;
struct BIT
{
    vector<int> bit;
    BIT(int n)
    {
        bit.resize(n + 4, 0);
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
vector<int> vals;
void solve()
{
    BIT fen(n);
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
    {
        fen.up(a[i], 1);
        ans += fen.query(a[i] + 1, n);
    }
    cout << ans;
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
