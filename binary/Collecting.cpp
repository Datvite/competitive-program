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
int n, v[N], w[N], k;
double c[N];
bool check(double mid)
{
    for (int i = 1; i <= n; i++)
        c[i] = v[i] - w[i] * mid;
    sort(c + 1, c + n + 1, greater<double>());
    double sum = 0;
    for (int i = 1; i <= k; i++)
        sum += c[i];
    return sum >= 0;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    double l = 0, r = 1e9, mid;
    for (int i = 1; i <= 100; i++)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << l;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    solve();
}
