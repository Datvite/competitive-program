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
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, a[N], k;
bool check(ll mid)
{
    ll cnt = k - 1, last = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - last >= mid)
        {
            cnt--;
            last = a[i];
        }
        if (cnt == 0)
            return 1;
    }
    return cnt == 0;
}
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll l = 1, r = 1e18, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    sol();
}
