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
int n, open[N], close[N], cnt = 0, suf[N], pre[N], pre1[N], fact[N], invfact[N], ans = 0;
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void cal()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invfact[N - 1] = binpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}
int nCk(int x, int y)
{
    if (y < 0 || y > x)
        return 0;
    return mul(fact[x], mul(invfact[y], invfact[x - y]));
}
string str;
void solve()
{
    for (int i = 1; i <= n; i++)
        if (str[i] == '(')
            open[i] = open[i - 1] + 1;
        else
            open[i] = open[i - 1];
    for (int i = n; i >= 1; i--)
        if (str[i] == ')')
            close[i] = close[i + 1] + 1;
        else
            close[i] = close[i + 1];
    for (int i = n; i >= 1; i--)
        if (str[i] == '?')
        {
            suf[i] = suf[i + 1] + 1;
            cnt++;
        }
        else
            suf[i] = suf[i + 1];
    // q2 - y >= open[i - 1] + x + 1 - close[i + 1]
    // q2 + close[i + 1] - open[i - 1] - 1 >= x + y
    if (cnt >= 0)
    {
        pre[0] = nCk(cnt, 0);
        for (int i = 1; i <= cnt; i++)
            pre[i] = (pre[i - 1] + nCk(cnt, i)) % MOD;
    }
    if (cnt >= 1)
    {
        pre1[0] = nCk(cnt - 1, 0);
        for (int i = 1; i <= cnt; i++)
            pre1[i] = (pre1[i - 1] + nCk(cnt - 1, i)) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == ')')
            continue;
        int d = open[i - 1] + 1 - close[i + 1];
        int cur1 = suf[i + 1] - d;
        int cur2 = 0;
        if (str[i] == '(')
            cur2 = cnt;
        else
            cur2 = cnt - 1;
        int lim = min(cur1, cur2);
        if (lim < 0)
        continue;
        //cout << pre[lim] << endl;
        if (str[i] == '(')
            ans += pre[lim];
        else
            ans += pre1[lim];
        ans %= MOD;
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
    str = " " + str;
    cal();
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
