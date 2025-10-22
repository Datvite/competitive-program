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
int n, t, a[N], b[N];
void solve()
{
    cin >> n;
    cout << add(a[n], b[n]) << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    a[1] = b[1] = 1;
    for (int i = 2; i <= 1e6 + 1; i++)
    {
        a[i] = add(mul(a[i - 1], 4), b[i - 1]);
        b[i] = add(mul(b[i - 1], 2), a[i - 1]);
    }
    while (t--)
        solve();
}
