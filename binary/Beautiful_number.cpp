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
int n, a[N];
bool check(int mid)
{
    return mid / 3 + mid / 5 + mid / 7 - mid / 15 - mid / 21 - mid / 35 + mid / 105 >= n;
}
void solve()
{
    int l = 1, r = 1e18, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
