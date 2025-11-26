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
int t, n, m, a[N], cnt[N], cur = 0, ans = 1e18;
void reset()
{
    memset(cnt, 0, (m + 1) * sizeof(int));
    cur = 0;
    ans = 1e18;
}
void solve()
{
    cin >> n >> m;
    reset();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                if (j <= m)
                {
                    cnt[j]++;
                    if (cnt[j] == 1)
                        cur++;
                }
                if (j * j != a[i])
                {
                    int k = a[i] / j;
                    if (k <= m)
                    {
                        cnt[k]++;
                        if (cnt[k] == 1)
                            cur++;
                    }
                }
            }
        }
        while (cur == m)
        {
            ans = min(ans, a[i] - a[l]);
            for (int j = 1; j * j <= a[l]; j++)
            {
                if (a[l] % j == 0)
                {
                    if (j <= m)
                    {
                        cnt[j]--;
                        if (cnt[j] == 0)
                            cur--;
                    }
                    if (j * j != a[l])
                    {
                        int k = a[l] / j;
                        if (k <= m)
                        {
                            cnt[k]--;
                            if (cnt[k] == 0)
                                cur--;
                        }
                    }
                }
            }
            l++;
        }
    }
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
