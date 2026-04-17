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
vector<ii> v[N];
ll dp[3010][3010], a[3010][3010];
ll x = 1;
ll d = 1;
ll j = 1;
ll mp[(ll)1e7];
void solve()
{
    ll n = 2023;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= x; j++)
        {
            a[i][j] = d * d;
            d++;
        }
        x++;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {

                if (i == 1)
                {
                    dp[i][j] = a[i][j];
                }
                else if (j == 1)
                {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                }
                else if (a[i][j + 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + a[i][j];
                }
                else if (i >= 2)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

                               - dp[i - 2][j - 1] + a[i][j];
                }
                else
                {
                    dp[i][j] = a[i][j];
                }
            }
            mp[(ll)sqrt(a[i][j])] = dp[i][j];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
}
signed main()
{
    ios;
    fopenn("");
    solve();
    ll tt = 1;
    cin >> tt;
    while (tt--)
    {
        ll n;
        cin >> n;
        cout << mp[n] << endl;
    }
}
// Hello, World!