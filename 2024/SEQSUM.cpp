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
ll n, a[N], l = 1, m, sum, ans = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        while (sum > m)
        {
            sum -= a[l];
            l++;
        }
        if (sum == m)
        {
            //cout << l << " " << i << endl;
            ans = min(ans, i - l + 1);
        }
    }
    if (ans == 1e18)
    cout << -1;
    else
    cout << ans;
}
main()
{
    skibidi;
    file("SEQSUM");
    cin >> n >> m;
    solve();
}
