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
#define int long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD = 2e9 + 11;
int add(int a, int b)
{
    return (a + b) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n;
iii a[N];
map<int, int> m;
bool cmp(const iii &a, const iii &b)
{
    if (a.fi != b.fi)
        return a.fi > b.fi;
    return a.se.se < b.se.se;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].se.fi;
        m[a[i].se.fi]++;
        a[i].se.se = i;
    }
        for (int i = 1; i <= n; i++)
            a[i].fi = m[a[i].se.fi];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        while (m[a[i].se.fi] > 0)
            {
                cout << a[i].se.fi << " ";
                m[a[i].se.fi]--;
            }
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
 