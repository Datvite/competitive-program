#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define str string
#define f(i, l, r) for (ll i = l; i <= r; i++)
#define task
#define F                            \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL);
using namespace std;
const ll N = 1e6 + 12;
ll n, m, res1 = 0, vt1, vt2, gmin = LLONG_MAX;
ll a[N];
unordered_map<ll, ll> M;
int main()
{
    F;
    if (fopen("ASUMMIN.INP", "r"))
    {
        freopen("ASUMMIN.INP", "r", stdin);
        freopen("ASUMMIN.OUT", "w", stdout);
    }
    cin >> n >> m;
    f(i, 1, n)
    {
        cin >> a[i];
        if(!M[a[i]])
        M[a[i]] = i;
    }
    sort(a + 1, a + n + 1);
    f(i, 1, m)
    {
        ll k;
        cin >> k;
        ll j = lower_bound(a + 1, a + n + 1, -k) - a;
        if (abs(a[j] + k) < gmin)
        {
            gmin = abs(a[j] + k);
            vt1 = M[a[j]];
            vt2 = i;
        }
        if (abs(a[j-1] + k) < gmin)
        {
            gmin = abs(a[j-1] + k);
            vt1 = M[a[j-1]];
            vt2 = i;
        }
        ll s = lower_bound(a + 1, a + n + 1, k) - a;
        if (abs(a[s] + k) < gmin)
        {
            gmin = abs(a[s] + k);
            vt1 = M[a[s]];
            vt2 = i;
        }
        if (abs(a[s-1] + k) < gmin)
        {
            gmin = abs(a[s-1] + k);
            vt1 = M[a[s-1]];
            vt2 = i;
        }
    }
    cout << vt1 << " " << vt2;
    return 0;
}
