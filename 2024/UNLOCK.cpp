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
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, a[N], m, f[N], ans = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i] + m;
    }
    sort(a + 1, a + 2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        f[i] = f[i - 1] + a[i];
    ll l = 1;
    for (int r = n; r <= 2 * n; r++, l++)
    {
        ll mid = (l + r) / 2;
        ans = min(ans, (mid - l + 1) * a[mid] - (f[mid] - f[l - 1]) + (f[r] - f[mid]) - (r - mid) * a[mid]);
    }
    cout << ans;
}
main()
{
    skibidi;
    file("UNLOCK");
    cin >> n >> m;
    solve();
}
