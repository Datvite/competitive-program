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
int n, a[N], dp[N], l[N], r[N];
int bit[N];
void upd(int i, int v)
{
    for (; i <= n; i += i & -i)
        bit[i] = max(bit[i], v);
}
int get(int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);

    return res;
}
vector<int> vec[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        cin >> r[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - 1 > 0)
            for (int x : vec[i - 1])
                upd(x, dp[x]);
        int maxn = i - l[i] - 1;
        dp[i] = 1 + get(maxn);
        if (i + r[i] < n)
            vec[i + r[i]].push_back(i);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
main()
{
    skibidi;
    file("BOUQUET");
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
