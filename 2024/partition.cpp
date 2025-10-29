#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
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
const int N = 2e3 + 69;
const int BASE = 256;
const int MOD = 2e9 + 11;
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
int n, a[N][N], m, dist[N][N], maxn, maxa;
int can[N][N];
bool vis[N][N];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
queue<ii> q;
ii bfs(ii S)
{
    q.push(S);
    vis[S.fi][S.se] = 1;
    int sum = a[S.fi][S.se], area = 1;
    while (!q.empty())
    {
        int u = q.front().fi, v = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u + dx[i];
            int y = v + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && can[x][y] && !vis[x][y])
            {
                vis[x][y] = 1;
                sum += a[x][y];
                area++;
                q.push({x, y});
            }
        }
    }
    return {sum, area};
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> can[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (can[i][j] && !vis[i][j])
            {
                ii ans = bfs({i, j});
                if (ans.fi > maxn || (ans.fi == maxn && ans.se < maxa))
                {
                    maxn = ans.fi;
                    maxa = ans.se;
                }
            }
        }
    }
    cout << maxn << " " << maxa;
}
main()
{
    skibidi;
    file("KHAITHAC");
    cin >> n >> m;
    solve();
}
