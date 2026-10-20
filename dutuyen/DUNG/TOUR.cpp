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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e3 + 69;
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
int n, m, a[N];
double dist[N][N];
double nd[N][N];
bool check(double mid)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] < 1e18)
                nd[i][j] = dist[i][j] - mid;
            else
                nd[i][j] = 1e18;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                nd[i][j] = min(nd[i][j], nd[i][k] + nd[k][j]);
    for (int i = 1; i <= n; i++)
        if (nd[i][i] < 0)
            return 1;
    return 0;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = 1e18;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    if (!check(MOD))
    {
        cout << "NO TOUR";
        return;
    }
    double l = 0, r = 1e9, ans = r;
    for (int i = 0; i < 40; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid;
        }
        else
            l = mid;
    }
    cout << fixed << setprecision(2) << ans;
}
main()
{
    skibidi;
    file("TOUR");
    cin >> n >> m;
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
