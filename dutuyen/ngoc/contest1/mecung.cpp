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
const int N = 1e6 + 69;
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
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char ch1[105][105];
char ch2[105][105];
int color(char c)
{
    if (c == 'C')
        return 0;
    if (c == 'P')
        return 1;
    if (c == 'Z')
        return 2;
    return 3;
}
int dist[107][107][16];
int bfs(int sx, int sy, int tx, int ty)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int mask = 0; mask < 16; mask++)
                dist[i][j][mask] = 1e18;
    deque<tuple<int, int, int>> dq;
    dist[sx][sy][0] = 0;
    dq.push_front({sx, sy, 0});
    while (!dq.empty())
    {
        auto [x, y, mask] = dq.front();
        dq.pop_front();
        int cur = dist[x][y][mask];
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            char c;
            if (d == 0)
                c = ch1[x][y];
            else if (d == 1)
                c = ch1[x][y - 1];
            else if (d == 2)
                c = ch2[x][y];
            else
                c = ch2[x - 1][y];
            int col = color(c);
            int nmask = mask | (1 << col);
            int cost;
            if ((mask >> col) & 1)
                cost = 0;
            else
                cost = 1;
            if (dist[nx][ny][nmask] > cur + cost)
            {
                dist[nx][ny][nmask] = cur + cost;
                if (cost == 0)
                    dq.push_front({nx, ny, nmask});
                else
                    dq.push_back({nx, ny, nmask});
            }
        }
    }
    int res = 1e18;
    for (int mask = 0; mask < 16; mask++)
        res = min(res, dist[tx][ty][mask]);
    return res;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            cin >> ch1[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ch2[i][j];
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << bfs(a, b, c, d) << '\n';
    }
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
