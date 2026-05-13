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
int n, q, a[N], sum[N], b[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    while (q--)
    {
        int k, m;
        cin >> k >> m;
        int l = 1, r = n, ans = 0;
        while (l <= r && m)
        {
            int c1;
            if (a[l] <= k)
                c1 = a[l];
            else
                c1 = 2 * k - a[l];
            int c2;
            if (a[r] <= k)
                c2 = a[r];
            else
                c2 = 2 * k - a[r];
            if (c1 < c2)
            {
                ans += c1;
                l++;
            }
            else
            {
                ans += c2;
                r--;
            }
            m--;
        }
        cout << ans << endl;
    }
}
void solve2()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int k, m;
    cin >> k >> m;
    q--;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k)
            b[i] = a[i];
        else
            b[i] = 2 * k - a[i];
    }
    sort(b + 1, b + n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + b[i];
    if (m > n)
            cout << sum[n] << endl;
        else
            cout << sum[m] << endl;
    while (q--)
    {
        cin >> k >> m;
        if (m > n)
            cout << sum[n] << endl;
        else
            cout << sum[m] << endl;
    }
}
int query(int k, int m)
{
    int l = 0, r = m, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        int le = mid + 1, ri = n - m + mid + 1;
        if (mid > 0 && a[le] > k)
            r = mid;
        else if (a[ri] <= k)
            l = mid + 1;
        else
        {
            int c1;
            if (le == 0)
                c1 = -1e18;
            else if (a[le] <= k)
                c1 = a[le];
            else
                c1 = 2 * k - a[le];
            int c2;
            if (a[ri] <= k)
                c2 = a[ri];
            else
                c2 = 2 * k - a[ri];
            if (c1 < c2)
                l = mid + 1;
            else
                r = mid;
        }
    }
    mid = l;
    return sum[mid] + 2 * k * (m - mid) - (sum[n] - sum[n - m + mid]);
}
void solve3()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    while (q--)
    {
        int k, m;
        cin >> k >> m;
        cout << query(k, m) << endl;
    }
}
main()
{
    skibidi;
    file("SOCOLA");
    cin >> n >> q;
    if (n <= 1e3 && q <= 1e3)
        solve();
    else
        solve3();
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
