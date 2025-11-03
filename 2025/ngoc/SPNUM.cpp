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
int n, a[N], ones;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ones++;
    }
    if (ones == 0)
        {
            cout << 0;
            return;
        }
    int curr = 0;
    for (int i = 1; i <= k; i++)
        if (a[i] == 1)
            curr++;
    int res = curr;
    for (int i = k + 1; i <= n; i++)
    {
        if (a[i - k] == 1)
            curr--;
        if (a[i] == 1)
            curr++;
        res = max(res, curr);
    }
    cout << ones - res;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
