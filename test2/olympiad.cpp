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
int n, c, k;
iii a[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].se.fi >> a[i].se.se;
        int cost;
        if (a[i].se.fi >= k)
            cost = 0;
        else if (a[i].se.se != 0)
            cost = ceil((long double)(k - a[i].se.fi) / a[i].se.se);
        else
            cost = 1e18;
        a[i].fi = cost;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        c -= a[i].fi;
        if (c < 0)
        {
            cout << i - 1;
            return;
        }
    }
    cout << n;
}
main()
{
    skibidi;
    file("");
    cin >> n >> c >> k;
    solve();
}
