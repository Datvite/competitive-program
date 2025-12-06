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
int t, n, X, a[N];
void solve()
{
    cin >> n >> X;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> v;
    int l = 1, r = n, sum = 0, last = 0, res = 0;
    while (l <= r)
    {
        while ((sum + a[r]) / X > last && l <= r)
        {
            res += a[r];
            sum += a[r];
            v.push_back(a[r]);
            r--;
            last = sum / X;
        }
        if (l > r)
            break;
        sum += a[l];
        v.push_back(a[l]);
        l++;
    }
    cout << res << endl ;
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
