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
int n, m, k, t1, t2, a[N], dist[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
deque<ii> dq;
bool cn[N][N];
bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs(ii S)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = 1e9;
    if (cn[S.fi][S.se] == 0)
    {
        dist[S.fi][S.se] = 0;
        dq.push_back(S);
    }
    else
    {
        dist[S.fi][S.se] = 1;
        dq.push_back(S);
    }
    while (!dq.empty())
    {
        ii u = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int x = u.fi + dx[i];
            int y = u.se + dy[i];
            if (inside(x, y) && dist[x][y] > dist[u.fi][u.se] + 1 && cn[x][y] == 1)
            {
                dist[x][y] = dist[u.fi][u.se] + 1;
                dq.push_back({x, y});
            }
            else if (inside(x, y) && dist[x][y] > dist[u.fi][u.se] && cn[x][y] == 0)
            {
                dist[x][y] = dist[u.fi][u.se];
                dq.push_front({x, y});
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= k; i++)
    {

        int u, v;
        cin >> u >> v;
        cn[u][v] = 1;
    }
    bfs({1, 1});
    cout << dist[t1][t2];
}
main()
{
    skibidi;
    file("MBALL");
    cin >> n >> m >> k >> t1 >> t2;
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
