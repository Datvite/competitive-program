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

int m, n, q, sx, sy;
int a[N][N], dist[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inside(int x, int y)
{
    return (1 <= x && x <= m && 1 <= y && y <= n);
}

void bfs01(int startX, int startY)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = 1e18;

    deque<ii> dq;
    dist[startX][startY] = 0;
    dq.push_back({startX, startY});

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (inside(nx, ny))
            {
                int w = (a[nx][ny] == a[x][y] ? 0 : 1);
                if (dist[nx][ny] > dist[x][y] + w)
                {
                    dist[nx][ny] = dist[x][y] + w;
                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
    }
}

void solve()
{
    cin >> sx >> sy;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    bfs01(sx, sy);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (inside(u, v) && dist[u][v] != 1e18)
            cout << dist[u][v] << endl;
        else
            cout << -1 << endl;
    }
}

main()
{
    skibidi;
    file("MECUNG3");
    cin >> m >> n >> q;
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
