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
int n, ti = 0, teo = 0, ans = 0;
iii a[N];
void solve()
{
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i].se.fi >> a[i].se.se;
        a[i].fi = abs(a[i].se.fi - a[i].se.se);
    }
    sort(a + 1, a + n + 1);
    ti = n;
    teo = n;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (ti > 0 && a[i].se.fi < a[i].se.se)
        {
            ans += a[i].se.fi;
            ti--;
        }
        else if (teo > 0)
        {
            ans += a[i].se.se;
            teo--;
        }
        else
        {
            ans += a[i].se.fi;
            ti--;
        }
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
