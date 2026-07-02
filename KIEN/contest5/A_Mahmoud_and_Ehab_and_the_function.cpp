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
int n, m, q, a[N], b[N], SA = 0, SB = 0, sb[N];
int cal(int x)
{
    int id = lower_bound(sb, sb + m - n + 1, x) - sb;
    int ans = 4e18;
    if (id <= m - n)
        ans = min(ans, abs(x - sb[id]));
            if (id > 0)
        ans = min(ans, abs(x - sb[id - 1]));
    return ans;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2 == 1)
            SA += a[i];
        else
            SA -= a[i];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (i % 2 == 1)
            SB += b[i];
        else
            SB -= b[i];
    sb[0] = SB;
    for (int j = 1; j <= m - n; j++)
        sb[j] = -sb[j - 1] + b[j] + (n % 2 == 1 ? b[j + n] : -b[j + n]);
    sort(sb, sb + m - n + 1);
    cout << cal(SA) << endl;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) % 2 != 0)
        {
            if (l % 2 == 1)
                SA += x;
            else
                SA -= x;
        }
        cout << cal(SA) << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> q;
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
