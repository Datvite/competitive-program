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
ll n, a[N], mask = 0, ans = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 32; i >= 0; i--)
    {
        mask = On(mask, i);
        ll tm = On(ans, i);
        unordered_set<ll> s;
        for (int j = 1; j <= n; j++)
            s.insert(a[j] & mask);
        for (auto j : s)
            if (s.count(j ^ tm))
            {
                ans = tm;
                break;
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