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
int n, x[N], y[N], ans = 0, ans1 = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    int mid = x[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
    {
        ans += abs(x[i] - mid);
        ans += abs(y[i] - i);
    }
    mid = y[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
    {
        ans1 += abs(y[i] - mid);
        ans1 += abs(x[i] - i);
    }
    cout << min(ans, ans1);
}
main()
{
    skibidi;
    file("ROBOT");
    cin >> n;
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
