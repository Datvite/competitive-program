#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
#define lcm(a, b) (a / __gcd(a, b) * b)
#define fi first
#define se second
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define fopenn(tenfile)                       \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
const ll mod = 1e9 + 7;
const ll base = 256;
const ll N = 1e6 + 11;
const ll LOG = 21;
inline ll add(ll a, ll b)
{
    return ((a % mod + b % mod) % mod + mod) % mod;
}
inline ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod) + mod) % mod;
}
inline ll sub(ll a, ll b)
{
    return ((a % mod - b % mod) % mod + mod) % mod;
}
vector<ll> v, g[N];
ll mp[1001][1001];
ll n;
ll d[N];
void backtrack(ll id)
{
    if (id > n)
    {
        ll cnt = 0;
        for (ll i = 2; i <= n; i++)
        {
            if (!d[i])
                cnt++;
        }
        v.push_back(cnt);
        return;
    }
    for (ll i = 1; i <= id - 1; i++)
    {
        d[i]++;
        backtrack(id + 1);
        d[i]--;
    }
}
void sub1()
{
    backtrack(2);
    ll res = 0;
    for (auto x : v)
        res += x;
    // cout<<res<<" "<<v.size()<<endl;
    cout << res * n % mod;
}
void solve()
{
    cin >> n;
    sub1();
}
signed main()
{
    ios;
    fopenn("");
    ll tt = 1; // cin>>tt;
    while (tt--)
    {
        solve();
    }
}
// Hello, World!