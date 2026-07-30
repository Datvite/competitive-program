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
const int MOD = 111539786;
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
int n, k, a[N], dp[N][N];
int backtrack(int id, int cnt)
{
    if (cnt >= k)
        return 0;
    if (id > n)
        return 1;
    if (dp[id][cnt] != -1)
        return dp[id][cnt];
    int res = 0;
    res = add(res, backtrack(id + 1, cnt + 1));
    res = add(res, backtrack(id + 1, 0));
    return dp[id][cnt] = res;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cout << backtrack(1, 0) << endl;
}
main()
{
    skibidi;
    file("DNPK");
    while (cin >> n >> k)
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
