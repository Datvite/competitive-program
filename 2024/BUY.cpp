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
#define ii pair<ll, ll>
#define iii pair<int, ii>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const ll N = 1e6 + 69;
const ll BASE = 256;
const ll MOD = 2e9 + 11;
ll add(ll a, ll b)
{
    return (a + b) % MOD;
}
ll sub(ll a, ll b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll n, re, ans = 0;
ii a[N];
void solve()
{
    for (ll i = 1; i <= n; i++)
        cin >> a[i].se >> a[i].fi;
    for (ll i = 1; i <= n; i++)
        {
            ll no = min(re, a[i].fi);
            re -= no;
            ans += no * a[i].se;
            if (re == 0)
                break;
        }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> re >> n;
    solve();
}
