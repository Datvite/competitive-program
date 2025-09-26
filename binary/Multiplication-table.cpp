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
int n, m, k;
bool check(int mid)
{
    if (m <= n)
    {
        int s = 0;
        for (int i = 1; i <= m; i++)
        {
            int j = mid / i;
            if (j >= 1)
            {
                s += min(j, n);
            }
            if (s >= k)
                return 1;
        }
        return 0;
    }
    else
    {
        int s = 0;
        for (int j = 1; j <= n; j++)
        {
            int i = mid / j;
            if (i >= 1)
            {
                s += min(i, m);
            }
            if (s >= k)
                return 1;
        }
        return 0;
    }
}
void solve()
{
    int l = 0, r = 9e18;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> m >> n >> k;
    solve();
}
