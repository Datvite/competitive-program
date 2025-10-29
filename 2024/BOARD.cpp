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
ll n, a[N][N], f[N][N], m, ans = -1e18;
vector<ii> v;
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i][j] = max({f[i - 1][j - 1], f[i][j - 1], f[i + 1][j - 1]}) + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][m]);
    cout << ans << endl;
    for (int j = m; j >= 1; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            if (f[i][j] == ans)
            {
                v.push_back({j, i});
                ans -= a[i][j];
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x.se << " " << x.fi << endl;
    }
}
main()
{
    skibidi;
    file("BOARD");
    cin >> n >> m;
    sol();
}
