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
const int Q = 1e3 + 69;
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
int n, a[Q][Q], ans = 1, vis[Q][Q], timer = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int bfs(int x, int y, int d)
{
    queue<iii> qu;
    qu.push({x, {y, d}});
    timer++;
    vis[x][y] = timer;
    int cnt = 1;
    while (!qu.empty())
    {
        iii top = qu.front();
        int cx = top.fi, cy = top.se.fi, cd = top.se.se;
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && vis[nx][ny] != timer && abs(a[nx][ny] - a[cx][cy]) == cd)
            {
                qu.push({nx, {ny, cd}});
                vis[nx][ny] = timer;
                cnt++;
            }
        }
    }
    return cnt;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int cx = i + dx[k];
                int cy = j + dy[k];
                if (1 <= cx && cx <= n && 1 <= cy && cy <= n && vis[cx][cy] == 0)
                {
                    ans = max(ans, bfs(cx, cy, abs(a[cx][cy] - a[i][j])));
                }
            }
        }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("RSELECT");
    cin >> n;
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
