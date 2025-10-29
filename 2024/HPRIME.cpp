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
vector<ll> ans;
bool prime[N];
bool check(ll val)
{
    ll nsum = 0;
    while (val > 0)
    {
        nsum += val % 10;
        val /= 10;
    }
    return nsum == k;
}
void sieve()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i<= n; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (prime[i] && check(i))
        {
            ans.push_back(i);
        }
    }
}
void sol()
{
    cout<< ans.size() << endl;
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
main()
{
    skibidi;
    file("HPRIME");
    cin >> n >> k;
    if (k >= 100)
    {
        cout << 0 << endl;
        exit(0);
    }
    memset(prime, 1, sizeof(prime));
    sieve();
    sol();
}
