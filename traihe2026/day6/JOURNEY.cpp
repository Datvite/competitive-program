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
const int N = 2e5 + 69;
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
int n, q, x[N], sum[N];
const int LOGN = 19;
int stmin[N][LOGN + 3], stmax[N][LOGN + 3];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            stmax[i][0] = 2 * x[i] - x[i - 1];
        else
            stmax[i][0] = 1e18;
        if (i < n)
            stmin[i][0] = 2 * x[i] - x[i + 1];
        else
            stmin[i][0] = -1e18;
    }

    for (int j = 1; j <= LOGN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    init();
    cin >> q;
    while (q--)
    {
        int s;
        cin >> s;
        int id = lower_bound(x + 1, x + n + 1, s) - x, l, r, ans = 0;
        bool cur = 0;
        if (id <= 1)
        {
            ans = x[1] - s;
            l = 1, r = 1;
        }
        else if (id > n)
        {
            ans = s - x[n];
            l = n, r = n, cur = 1;
        }
        else
        {
            int dl = s - x[id - 1];
            int dr = x[id] - s;
            if (dl <= dr)
            {
                ans = dl;
                l = id - 1, r = id - 1;
            }
            else
            {
                ans = dr;
                l = id, r = id, cur = 1;
            }
        }
        while (l > 1 || r < n)
        {
            if (cur)
            {
                int dl, dr;
                if (l > 1)
                    dl = x[r] - x[l - 1];
                else
                    dl = 1e18;
                if (r < n)
                    dr = x[r + 1] - x[r];
                else
                    dr = 1e18;
                if (dr < dl)
                {
                    int sl, idr = r;
                    if (l > 1)
                        sl = x[l - 1];
                    else
                        sl = -1e18;
                    for (int j = LOGN; j >= 0; j--)
                    {
                        if (idr + (1 << j) <= n)
                        {
                            if (stmin[idr][j] > sl)
                            {
                                idr += 1 << j;
                            }
                        }
                    }
                    ans += x[idr] - x[r];
                    r = idr;
                    cur = 1;
                }
                else
                {
                    ans += dl;
                    l--;
                    cur = 0;
                }
            }
            else
            {
                int dl, dr;
                if (l > 1)
                    dl = x[l] - x[l - 1];
                else
                    dl = 1e18;
                if (r < n)
                    dr = x[r + 1] - x[l];
                else
                    dr = 1e18;
                if (dl <= dr)
                {
                    int sr, idl = l;
                    if (r < n)
                        sr = x[r + 1];
                    else
                        sr = 1e18;
                    for (int j = LOGN; j >= 0; j--)
                    {
                        if (idl - (1 << j) >= 1)
                        {
                            if (stmax[idl - (1 << j) + 1][j] <= sr)
                            {
                                idl -= 1 << j;
                            }
                        }
                    }
                    ans += x[l] - x[idl];
                    l = idl;
                    cur = 0;
                }
                else
                {
                    ans += dr;
                    r++;
                    cur = 1;
                }
            }
        }
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("");
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
