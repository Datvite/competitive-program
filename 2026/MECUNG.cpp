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

int m, n, sx, sy;
int a[N][N], dist[N][N];
ii trace[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inside(int x, int y)
{
    return (1 <= x && x <= m && 1 <= y && y <= n);
}

bool check(int x, int y)
{
    return (x == 1 || x == m || y == 1 || y == n);
}

void solve()
{
    cin >> sx >> sy;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = -1;

    queue<ii> qu;
    dist[sx][sy] = 1;
    trace[sx][sy] = {-1, -1};
    qu.push({sx, sy});

    ii res = {-1, -1};

    if (check(sx, sy))
    {
        res = {sx, sy};
    }
    else
    {
        while (!qu.empty())
        {
            auto [x, y] = qu.front();
            qu.pop();

            if (check(x, y))
            {
                res = {x, y};
                break;
            }

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (inside(nx, ny) && a[nx][ny] == 0 && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    trace[nx][ny] = {x, y};
                    qu.push({nx, ny});
                }
            }
        }
    }

    if (res.fi == -1)
    {
        cout << 0 << endl;
        return;
    }

    cout << dist[res.fi][res.se] << endl;

    vector<ii> path;
    ii cur = res;
    while (cur.fi != -1)
    {
        path.push_back(cur);
        cur = trace[cur.fi][cur.se];
    }
    reverse(all(path));

    for (auto [x, y] : path)
        cout << x << " " << y << endl;
}

main()
{
    skibidi;
    file("MECUNG");
    cin >> m >> n;
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
