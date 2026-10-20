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
int n, k, a[N], s[N], ans = 0;
vector<int> vals;
struct Fenwick
{
    int n;
    vector<long long> bit;
    Fenwick(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void add(int i, long long val)
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    long long sum(int i)
    {
        long long res = 0;

        for (; i > 0; i -= i & -i)
            res += bit[i];

        return res;
    }
};
void solve()
{
    s[0] = 0;
    vals.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= k;
        s[i] = s[i - 1] + a[i];
        //cout << s[i] << " ";
        vals.push_back(s[i]);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    Fenwick BIT(vals.size());
    for (int i = 0; i <= n; i++)
        s[i] = lower_bound(all(vals), s[i]) - vals.begin() + 1;
    BIT.add(s[0], 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = BIT.sum(s[i]);
        ans += cur;
        BIT.add(s[i], 1);
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("HWORK");
    cin >> n >> k;
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
