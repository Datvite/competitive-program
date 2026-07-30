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
const int N = 1e2 + 69;
const int INF = 1e9;
const int BASE = 256;
const int MOD = 1e9 + 7;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
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
int n, k, a[N], ans[N][N];
bool vis[N][N];
bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
vector<ii> res;
int cnt(int x, int y)
{
    int cur = 0;
    for (int id = 0; id < 8; id++)
    {
        int nx = x + dx[id];
        int ny = y + dy[id];
        if (inside(nx, ny) && !vis[nx][ny])
            cur++;
    }
    return cur;
}
bool solve(int sx, int sy)
{
    int cx = sx, cy = sy;
    vis[cx][cy] = 1;
    res.push_back({cx, cy});
    for (int step = 1; step < n * n; step++)
    {
        int minn = INF;
        int nextx = -1, nexty = -1;
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (inside(nx, ny) && !vis[nx][ny])
            {
                int deg = cnt(nx, ny);
                if (deg < minn)
                {
                    minn = deg;
                    nextx = nx;
                    nexty = ny;
                }
            }
        }
        if (nextx == -1)
            return 0;
        cx = nextx;
        cy = nexty;
        vis[cx][cy] = 1;
        res.push_back({cx, cy});
    }
    return 1;
}
vector<ii> vec;
main()
{
    skibidi;
    file("");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vec.push_back({i, j});
        }
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(vec.begin(), vec.end(), rng);
    bool check = 0;
    for (auto [x, y] : vec)
    {
        res.clear();
        memset(vis, 0, sizeof(vis));
        if (solve(x, y))
        {
            check = 1;
            break;
        }
    }
    int sz = (n * n) / k;
    int remain = (n * n) % k;
    int id = 0;
    for (int color = 1; color <= k; color++)
    {
        int curs;
        if (color <= remain)
            curs = sz + 1;
        else
            curs = sz;
        for (int i = 0; i < curs; i++)
        {
            if (id < res.size())
            {
                ans[res[id].fi][res[id].se] = color;
                id++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
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
