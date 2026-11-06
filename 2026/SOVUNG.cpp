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

int m, n, k;
bool blocked[N][N], vis[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inside(int x, int y)
{
    return (1 <= x && x <= m && 1 <= y && y <= n);
}

void bfs(int startX, int startY)
{
    queue<ii> qu;
    vis[startX][startY] = true;
    qu.push({startX, startY});

    while (!qu.empty())
    {
        auto [x, y] = qu.front();
        qu.pop();

        for (int step = 0; step < 4; step++)
        {
            int nx = x + dx[step];
            int ny = y + dy[step];

            if (inside(nx, ny) && !blocked[nx][ny] && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                qu.push({nx, ny});
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        for (int r = x1; r <= x2; r++)
            for (int c = y1; c <= y2; c++)
                blocked[r][c] = true;
    }

    int regions = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!blocked[i][j] && !vis[i][j])
            {
                regions++;
                bfs(i, j);
            }
        }
    }

    cout << regions << endl;
}

main()
{
    skibidi;
    file("SOVUNG");
    cin >> m >> n >> k;
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
