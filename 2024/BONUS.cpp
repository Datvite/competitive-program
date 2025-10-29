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
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask & ~(1LL << pos))
#define Not(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e3 + 69;
ll n, a[N][N], minx = 1e18, maxx = -1e18, miny = 1e18, maxy = -1e18, d[N], ans = 0;
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[x + 200][y + 200] = z;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    for (int i = miny; i <= maxy; i++)
    {
        for (int j = miny; j < i; j++)
        {
            for (int k = minx; k <= maxx; k++)
            {
                ll x = a[k + 200][i + 200], y = a[k + 200][j + 200];
                if (x != 0 && y != 0 && x != y)
                {
                    ll mask = (1 << (x - 1)) | (1 << (y - 1));
                    ans += d[15 ^ mask];
                    d[mask]++;
                }
            }
            //cout<<i<<endl;
            memset(d, 0, sizeof(d));
        }
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    sol();
}
