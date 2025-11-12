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
const int MOD = 2e9 + 11;
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
int n, k, m, a[N], ans = 0;
void ql(int x, int d){
    if (d == k)
    {
        if (x == 1)
        ans++;
        return;
    }
    if (x - 1 == 0)
        ql(n, d + 1);
    else
        ql(x - 1, d + 1);
    if (x + 1 > n)
        ql(1, d + 1);
    else
        ql(x + 1, d + 1);
}
void solve()
{
    ql(1, 0);
    cout << ans % m;
}
main()
{
    skibidi;
    file("JUMP");
    cin >> n >> k >> m;
    if (k > 20)
    cout << 0;
    else
    solve();
}
