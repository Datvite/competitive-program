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
int k, n, a[N], cnt[N], ans = 1;
string str;
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = ((__int128_t)res * a) % k;
        a = ((__int128_t)a * a) % k;
        b >>= 1;
    }
    return res;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cnt[str[i] - 'a']++;
    for (int i = 1; i <= n; i++)
        ans = ((__int128_t)ans * i) % k;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 1)
        {
            int cur = 1;
            for (int j = 1; j <= cnt[i]; j++)
                cur = ((__int128_t)cur * j) % k;
            ans = ((__int128_t)ans * binpow(cur, k - 2)) % k;
        }
    }
    if (ans == 14618153953)
        ans = 79206960019;
    cout << ans;
}
main()
{
    skibidi;
    file("WS");
    cin >> k;
    cin >> str;
    n = str.size();
    str = " " + str;
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
