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
const int MOD = 998244353;
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
int t, n, a[N], s0, s1, ans = 0, pre[N];
void reset()
{
    s0 = 0;
    s1 = 0;
    ans = 0;
}
void solve()
{
    cin >> n;
    reset();
    string s;
    cin >> s;
    s = " " + s;
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            ans = add(ans, res);
        res = mul(res, 2);
    }
    for (int i = 1; i <= n; i++)
        {
            int tmp;
            if (s[i] == '(')
                tmp = 1;
            else
                tmp = -1;
            pre[i] = pre[i - 1] + tmp;
        }
    for (int i = 1; i <= n; i++)
    {
        if (pre[i - 1] < 2)
            s0 = 0;
        if (s[i] == ')')
        {
            ans = add(ans, add(s0, s1 + 1));
            s1 = add(s1, add(s1 + 1, s0));
        }
        else
        {
            s0 = add(s0, add(s0, s1 + 1));
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
