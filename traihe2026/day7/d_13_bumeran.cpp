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
const int N = 1e3 + 69;
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
int n, a[N], dp[N][N], nextf[N], nextr[N];
string str;
int f(int id, int cnt)
{
    if (id >= n)
        return cnt == 0;
    if (dp[id][cnt] != -1)
        return dp[id][cnt];
    int res = cnt == 0;
    if (cnt >= 1 && nextr[id] < n)
        res = f(nextr[id] + 1, cnt - 1);
    if (nextf[id] < n)
        res = add(res, f(nextf[id] + 1, cnt + 1));
    return dp[id][cnt] = res;
}
void solve()
{
    int F = n, R = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'F')
            F = i;
        else
            R = i;
        nextf[i] = F;
        nextr[i] = R;
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) - 1;
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
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
