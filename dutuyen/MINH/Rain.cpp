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
int n, m, a[N][N], ans = 0;
struct GridDijkstra
{
    int n, m;
    vector<vector<bool>> vis;
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    GridDijkstra(int _n = 0, int _m = 0)
    {
        n = _n;
        m = _m;
        vis.assign(n + 1, vector<bool>(m + 1, 0));
    }
    bool inside(int x, int y)
    {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    }
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    void run()
    {
        while (!pq.empty())
        {
            auto [du, cur] = pq.top();
            pq.pop();
            auto [x, y] = cur;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (!inside(nx, ny))
                    continue;
                int w = a[nx][ny];
                if (!vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    ans += max(0LL, du - w);
                    pq.push({max(du, w), {nx, ny}});
                }
            }
        }
    }
};
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    GridDijkstra dijk(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 || i == n || j == 1 || j == m)
            {
                dijk.pq.push({a[i][j], {i, j}});
                dijk.vis[i][j] = 1;
            }
        }
    }
    dijk.run();
    cout << ans;
}
main()
{
    skibidi;
    file("");
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
