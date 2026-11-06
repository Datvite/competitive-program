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
char a[N][N], move_to[N][N];
bool vis[N][N];
ii trace[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'N', 'S', 'W', 'E'};

bool inside(int x, int y)
{
    return (1 <= x && x <= m && 1 <= y && y <= n);
}

bool is_border(int x, int y)
{
    return (x == 1 || x == m || y == 1 || y == n);
}

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '*')
            {
                sx = i;
                sy = j;
            }
        }
    }

    if (is_border(sx, sy))
    {
        cout << "" << endl;
        return;
    }

    queue<ii> qu;
    vis[sx][sy] = true;
    qu.push({sx, sy});

    ii dest = {-1, -1};

    while (!qu.empty())
    {
        auto [x, y] = qu.front();
        qu.pop();

        if (is_border(x, y))
        {
            dest = {x, y};
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (inside(nx, ny) && a[nx][ny] != '#' && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                trace[nx][ny] = {x, y};
                move_to[nx][ny] = dir[k];
                qu.push({nx, ny});
            }
        }
    }

    if (dest.fi != -1)
    {
        string ans = "";
        ii cur = dest;
        while (cur != make_pair(sx, sy))
        {
            ans += move_to[cur.fi][cur.se];
            cur = trace[cur.fi][cur.se];
        }
        reverse(all(ans));
        cout << ans << endl;
    }
}

main()
{
    skibidi;
    file("LABYRINTH");
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
