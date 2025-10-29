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
int n, a[N], m, b[N], ans = 0, maxb = 0;
bool mark[N];
int c[N];
void solve()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            maxb = max(maxb, b[i]) ;
        }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int cur = a[i], cnt = 1;
        if (c[a[i]] != 0)
            {
                cur = a[i];
                cnt = c[a[i]] / a[i];
            }
        while (cur)
        {
            if (!mark[a[i] * cnt])
            {
                mark[a[i] * cnt] = 1;
                cur--;
            }
            if (a[i] * (cnt + 1) > maxb)
                break;
            cnt++;
        }
        c[a[i]] = a[i] * cnt;
    }
    for (int i = 1; i <= m; i++)
        if (mark[b[i]])
            ans++;
    cout << ans;
}
main()
{
    skibidi;
    file("GIFTS1");
    solve();
}