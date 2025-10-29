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
ll n, a[N], t, l;
void solve()
{
    ll sum = 0;
    priority_queue<ll, vector<ll>> q;
    for (ll i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '+')
            {
                ll x;
                cin >> x;
                q.push(x);
            }
        else if (!q.empty())
        {
            ll x = q.top();
            while (!q.empty() && x == q.top())
            {
                q.pop();
            }
        }  
    }
    ll x = -1, cnt = 0;
    while (!q.empty())
    {
        if (x != q.top())
        {
            x = q.top();
            a[cnt++] = x;
        }
        q.pop();
    }
    cout << cnt << endl;
    for (ll i = 0; i < cnt; i++)
    {
        cout << a[i] << " ";
    }
}
main()
{
    skibidi;
    file("PQ");
    cin >> n;
    solve();
}
