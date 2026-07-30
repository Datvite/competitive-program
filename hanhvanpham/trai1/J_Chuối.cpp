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
const int N = 3e5 + 69;
const int LOG = 20;
const int BASE = 256;
const int MOD = 1e9 + 7;
const int inf = 1e18;
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

int theta, n, q, a[N], f1[N], f2[N];
int stmin[N][LOG], stmax[N][LOG], st[N][LOG];
int lmin[N], lmax[N], rmin[N], rmax[N];

int getmin(int l, int r)
{
    int k = __lg(r - l + 1);
    return min(stmin[l][k], stmin[r - (1 << k) + 1][k]);
}

int getmax(int l, int r)
{
    int k = __lg(r - l + 1);
    return max(stmax[l][k], stmax[r - (1 << k) + 1][k]);
}

int get(int l, int r)
{
    r--;
    if (l > r)
        return -inf;
    int k = __lg(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        stmin[i][0] = a[i];
        stmax[i][0] = a[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }

    lmin[0] = -inf;
    lmax[0] = -inf;
    f1[0] = 0;
    rmin[n + 1] = -inf;
    rmax[n + 1] = -inf;
    f2[n + 1] = 0;

    lmin[1] = -a[1];
    lmax[1] = a[1];
    f1[1] = 0;

    rmin[n] = -a[n];
    rmax[n] = a[n];
    f2[n] = 0;
    for (int i = 2; i <= n; i++)
    {
        f1[i] = max({f1[i - 1], lmax[i - 1] - a[i], lmin[i - 1] + a[i]});
        lmin[i] = max(lmin[i - 1], f1[i - 1] - a[i]);
        lmax[i] = max(lmax[i - 1], f1[i - 1] + a[i]);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        f2[i] = max({f2[i + 1], rmax[i + 1] - a[i], rmin[i + 1] + a[i]});
        rmin[i] = max(rmin[i + 1], f2[i + 1] - a[i]);
        rmax[i] = max(rmax[i + 1], f2[i + 1] + a[i]);
    }

    cout << f1[n] << " ";

    for (int i = 1; i <= n; i++)
        st[i][0] = f1[i] + f2[i + 1];

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }

    while (q--)
    {
        char t;
        int l, r;
        cin >> t >> l >> r;
        if (l > r)
            swap(l, r);

        if (t == 'H')
        {
            cout << get(l, r) << " ";
            continue;
        }

        int maxx = getmax(l, r);
        int minn = getmin(l, r);
        int ans = -inf;

        ans = max(ans, f1[l - 1] + maxx - minn + f2[r + 1]);

        if (l > 1)
        {
            ans = max(ans, lmax[l - 1] - minn + f2[r + 1]);
            ans = max(ans, lmin[l - 1] + maxx + f2[r + 1]);
        }
        if (r < n)
        {
            ans = max(ans, rmax[r + 1] - minn + f1[l - 1]);
            ans = max(ans, rmin[r + 1] + maxx + f1[l - 1]);
        }
        if (l > 1 && r < n)
        {
            ans = max(ans, lmax[l - 1] + rmin[r + 1]);
            ans = max(ans, lmin[l - 1] + rmax[r + 1]);
        }
        cout << ans << " ";
    }
}
main()
{
    skibidi;
    file("lyson");
    cin >> theta;
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
