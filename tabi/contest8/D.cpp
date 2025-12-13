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
int t, n, m, a[N], sum[N], sum1 = 0, sum2 = 0, ans = 0;
priority_queue<int, vector<int>, greater<int>> pqg;
priority_queue<int, vector<int>, less<int>> pql;
void reset()
{
    ans = 0;
    sum1 = 0;
    sum2 = 0;
    while (!pqg.empty())
        pqg.pop();
    while (!pql.empty())
        pql.pop();
}
void solve()
{
    reset();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
            cin >> a[i];
    for (int i = m; i >= 2; i--)
    {
        sum1 += a[i];
        if (a[i] > 0)
            pql.push(a[i]);
        while (sum1 > 0 && !pql.empty())
        {
            int x = pql.top();
            pql.pop();
            sum1 -= 2 * x;
            ans++;
        }
    }
    for (int i = m + 1; i <= n; i++)
    {
        sum2 += a[i];
        if (a[i] < 0)
            pqg.push(a[i]);
        while (sum2 < 0 && !pqg.empty())
        {
            int x = pqg.top();
            pqg.pop();
            sum2 -= 2 * x;
            ans++;
        }
    }
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
