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
int n, a[N], maxumin = -1e18, minumax = 1e18, maxvmin = -1e18, minvmax = 1e18;
int cal(int l, int r, int rem)
{
    if (l > r)
        return 0;
    if (abs(l) % 2 != rem)
        l++;
    if (abs(r) % 2 != rem)
        r--;
    if (l > r)
        return 0;
    return (r - l) / 2 + 1;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int umax = -1e18, umin = 1e18, vmax = -1e18, vmin = 1e18;
        for (int j = 1; j <= 4; j++)
        {
            int x, y;
            cin >> x >> y;
            int u = x + y;
            int v = x - y;
            umax = max(umax, u);
            umin = min(umin, u);
            vmax = max(vmax, v);
            vmin = min(vmin, v);
        }
        maxumin = max(maxumin, umin);
        minumax = min(minumax, umax);
        maxvmin = max(maxvmin, vmin);
        minvmax = min(minvmax, vmax);
    }
    int UL = maxumin + 1;
    int UR = minumax - 1;
    int VL = maxvmin + 1;
    int VR = minvmax - 1;
    if (UL > UR || VL > VR)
    {
        cout << 0;
        return;
    }
    int u1 = cal(UL, UR, 0);
    int u2  = cal(UL, UR, 1);
    int v1 = cal(VL, VR, 0);
    int v2  = cal(VL, VR, 1);
    int ans = (u1 * v1) + (u2 * v2);
    cout << ans << endl;
}
main()
{
    skibidi;
    file("PINPOS");
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
