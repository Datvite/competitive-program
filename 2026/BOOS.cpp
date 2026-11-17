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
#define all(x) x.begin(), x.end()
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
const int MOD = 1e9 + 7;
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
int n, m, a[N], b[N], c[N], d[N], sum1[N], sum0[N], maxans = 0, mindiff = 1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= m; i++)
    {
        c[i] = a[n - i + 1];
        d[i] = b[n - i + 1];
    }
    for (int i = 1; i <= m; i++)
    {
        sum1[i] = c[i] + d[m - i + 1];
        sum0[i] = d[i] + c[m - i + 1];
    }
    sort(sum1 + 1, sum1 + m + 1);
    sort(sum0 + 1, sum0 + m + 1);
    if (sum1[m] - sum1[1] < mindiff)
        {
            mindiff = sum1[m] - sum1[1];
            maxans = sum1[1];
        }
    if (sum0[m] - sum0[1] < mindiff)
        {
            mindiff = sum0[m] - sum0[1];
            maxans = sum0[1];
        }
    cout << maxans << " " << mindiff;
}
main()
{
    skibidi;
    file("boos");
    cin >> n >> m;
    solve();
}
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
