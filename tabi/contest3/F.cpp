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
int t, n, k, a[N], b[N];
bool check(int mid)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mid)
            continue;
        cnt += (a[i] - mid) / b[i] + 1;
    }
    return cnt <= k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int l = 0, r = 1e9, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < ans)
            continue;
        int cur = (a[i] - ans) / b[i] + 1;
        sum += cur * a[i] - b[i] * (cur * (cur - 1) / 2);
        cnt += cur;
    }
    cout << sum - (k - cnt) * ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
