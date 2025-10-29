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
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 22;
const int MOD = 1e9 + 7;
ll n, a[N][N], f[N][(1 << N)], ans = 1e18;
vector<ll>m[N];
void sol()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    f[0][0] = 1;
    for (int mask = 0; mask <= (1 << n) - 1; mask++)
        m[__builtin_popcount(mask)].push_back(mask);
    for (int i = 0; i < n; i++)
        for (auto mask : m[i + 1])
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] && ((mask >> j) & 1))
                {
                    f[i + 1][mask] += f[i][Off(mask, j)];
                    f[i + 1][mask] %= MOD;
                }
            }
        }
    cout << f[n][(1 << n) - 1];
}
main()
{
    skibidi;
    file("");
    cin >> n;
    sol();
}
