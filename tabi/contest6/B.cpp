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
int t, n, a[N];
int bit[N];
void reset()
{
    for (int i = 1; i <= n; i++)
        bit[i] = 0;
}
int get(int p)
{
    int idx = p, ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void update(int u, int v)
{
    int idx = u;
    while (idx <= n)
    {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}
void solve()
{
    cin >> n;
    reset();
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        res += get(n) - get(idx);
        update(idx, 1);
    }
    cout << res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
