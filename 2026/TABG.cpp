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
const int M = 1e6 + 69;
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
int n, m, k, dist[N][N], x[M], y[M];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char ch[N][N];
deque<ii> dq;
bool inside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs01()
{
    while (!dq.empty())
    {
        ii u = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = u.fi + dx[i];
            int ny = u.se + dy[i];
            if (inside(nx, ny))
            {
                if (ch[nx][ny] != ch[u.fi][u.se] && dist[nx][ny] > dist[u.fi][u.se] + 1)
                {
                    dist[nx][ny] = dist[u.fi][u.se] + 1;
                    dq.push_back({nx, ny});
                }
                else if (ch[nx][ny] == ch[u.fi][u.se] && dist[nx][ny] > dist[u.fi][u.se])
                {
                    dist[nx][ny] = dist[u.fi][u.se];
                    dq.push_front({nx, ny});
                }
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = 1e18;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '*')
            {
                dist[i][j] = 0;
                dq.push_back({i, j});
            }
        }
    for (int i = 1; i <= k; i++)
        cin >> x[i] >> y[i];
    bfs01();
    for (int i = 1; i <= k; i++)
        cout << dist[x[i]][y[i]] << endl;
}
main()
{
    skibidi;
    file("TABG");
    cin >> n >> m >> k;
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
