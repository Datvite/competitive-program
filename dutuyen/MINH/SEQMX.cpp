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
int n, v[N], k;
long double sum[N + 7];
bool check(long double x)
{
    memset(sum, 0, sizeof(sum));
    long double minn = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (v[i] - x);
        if (i >= k)
        {
            if (sum[i] - minn >= 0)
                return 1;
            minn = min(minn, sum[i - k + 1]);
        }
    }
    return 0;
}

void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    long double l = -1e10, r = 1e10, mid;
    for (int i = 1; i <= 100; i++)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(5) << l;
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
