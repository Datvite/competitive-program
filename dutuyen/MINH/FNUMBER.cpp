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
int t, n, a[N];
string s;
long long dp[10007][9][33][2];
long long dfs(int pos, int tight, int d9, int mask, int start)
{
    if (pos == (int)s.size())
    {
        if (d9 == 3 || d9 == 6)
            return 1;
        return 0;
    }
    int len = s.size() - pos;
    if (!tight && dp[len][d9][mask][start] != -1)
        return dp[len][d9][mask][start];
    int res = 0;
    int lim = tight ? (s[pos] - '0') : 9;
    for (int d = 0; d <= lim; d++)
    {
        int ntight = tight && (d == lim);
        int rem = d % 5, newmask = mask;
        bool check = 1;
        bool newstart = start | (d != 0);
        if (!newstart)
        {
            res += dfs(pos + 1, ntight, d9, newmask, newstart);
            res %= MOD;
            continue;
        }
        if (rem == 0)
        {
            if (mask & (1LL << 0))
                check = 0;
            else
                newmask |= (1LL << 0);
        }
        else if (rem == 1)
        {
            if (mask & (1LL << 4))
                check = 0;
            else
                newmask |= (1LL << 1);
        }
        else if (rem == 2)
        {
            if (mask & (1LL << 3))
                check = 0;
            else
                newmask |= (1LL << 2);
        }
        else if (rem == 3)
        {
            if (mask & (1LL << 2))
                check = 0;
            else
                newmask |= (1LL << 3);
        }
        else if (rem == 4)
        {
            if (mask & (1LL << 1))
                check = 0;
            else
                newmask |= (1LL << 4);
        }
        if (check)
        {
            res += dfs(pos + 1, ntight, (d9 + d) % 9, newmask, newstart);
            res %= MOD;
        }
    }
    if (!tight)
        return dp[len][d9][mask][start] = res;
    return res;
}

int calc()
{
    return dfs(0, 1, 0, 0, 0);
}
bool check(string s)
{
    int id = 0;
    while (id < (int)s.size() && s[id] == '0')
        id++;
    if (id == (int)s.size())
        return 0;
    int d9 = 0;
    bool vis[5] = {false};
    for (int i = id; i < (int)s.size(); i++)
    {
        int d = s[i] - '0';
        d9 = (d9 + d) % 9;
        int rem = d % 5;
        int comp = (5 - rem) % 5;
        if (vis[comp])
            return 0;
        vis[rem] = 1;
    }

    return (d9 == 3 || d9 == 6);
}
string l, r;
void solve()
{
    cin >> l >> r;
    s = r;
    int rval = calc();
    s = l;
    int lval = calc();
    cout << sub(rval, lval) + check(l) << endl;
}
int sum[N];
void solve2()
{
    for (int i = 0; i < N; i++)
        if (check(to_string(i)))
            sum[i] = 1;
    for (int i = 1; i < N; i++)
        sum[i] += sum[i - 1];
    while (t--)
    {
        int u, v;
        cin >> u >> v;
        cout << sum[v] - sum[u - 1] << endl;
    }
}
main()
{
    skibidi;
    file("FNUMBER");
    cin >> t;
    memset(dp, -1, sizeof(dp));
    if (t <= 100)
        while (t--)
            solve();
    else
        solve2();
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
