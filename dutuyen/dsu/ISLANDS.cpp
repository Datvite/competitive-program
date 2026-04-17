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
int n, m, a[N][N], mx = 0, par[N * N], sz[N * N], tplt = 0, ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<iii> islands;
int cd(int x, int y)
{
    return (x - 1) * m + y;
}
int acs(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = acs(par[x]);
}
void join(int x, int y)
{
    x = acs(x);
    y = acs(y);
    if (x != y)
    {
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        tplt--;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            par[cd(i, j)] = cd(i, j);
            sz[cd(i, j)] = 1;
            islands.push_back({a[i][j], {i, j}});
        }
    }
    sort(islands.begin(), islands.end(), greater<iii>());
    int l = 0;
    for (int i = mx; i >= 1; i--)
    {
        while (l < islands.size() && islands[l].fi >= i)
        {
            tplt++;
            int x = islands[l].se.fi, y = islands[l].se.se;
            l++;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] >= i)
                    join(cd(x, y), cd(nx, ny));
            }
        }
        ans = max(ans, tplt);
    }
    cout << ans;
}
main()
{
    skibidi;
    file("ISLANDS");
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
