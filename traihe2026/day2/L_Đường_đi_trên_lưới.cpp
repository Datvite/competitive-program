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
const int N = 1e3 + 21;
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
const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};
int O, n, m, q, theta;
char grid[N][N];
int dp[N][N], de[N][N], vt[N][N];

void bfs(int k)
{
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            dp[i][j] = 0;
    dp[n][m] = 1;
    for (int i = n; i > 0; i--)
    {
        for (int j = m; j > 0; j--)
        {
            vt[i][j] = 0;
            de[i][j] = 0;
            if (i == n && j == m)
                continue;

            if (dp[i + 1][j] <= k)
                dp[i][j] += dp[i + 1][j];
            else
                dp[i][j] = k;
            if (k - dp[i][j] >= dp[i][j + 1])
                dp[i][j] += dp[i][j + 1];
            else
                dp[i][j] = k;
            if (k - dp[i][j] >= dp[i + 1][j + 1])
                dp[i][j] += dp[i + 1][j + 1];
            else
                dp[i][j] = k;
        }
    }
    queue<pair<int, ii>> qu;
    qu.push({1, {1, 1}});
    cout << grid[1][1];
    vector<ii> vec[28];
    int p[28];
    char t[28];
    for (int i = 0; i < 26; i++)
    {
        t[i + (i >= (grid[n][m] - 'a'))] = char(i + 'a');
        t[grid[n][m] - 'a'] = grid[n][m];
    }

    for (int l = 1; l <= n + m; l++)
    {
        for (int num = 0; num < 27; num++)
        {
            vec[num].clear();
            p[num] = 0;
        }
        while (!qu.empty())
        {
            int u = qu.front().se.fi;
            int v = qu.front().se.se;
            int dem = qu.front().fi;
            if (u == n && v == m)
                return;
            qu.pop();
            for (int i = 0; i < 3; i++)
            {
                int x = u + dx[i];
                int y = v + dy[i];
                if (x <= n && y <= m && x > 0 && y > 0)
                {
                    if (x < n || y < m)
                    {
                        if (vt[x][y] != l)
                            vec[grid[x][y] - 'a' + (grid[x][y] >= grid[n][m])].push_back({x, y});
                        if (k - dem <= de[x][y])
                            de[x][y] = k;
                        else
                            de[x][y] += dem;
                        int ans = 0;
                        if (k / dem >= dp[x][y])
                            ans = dem * dp[x][y];
                        else
                            ans = k;
                        int idx = grid[x][y] - 'a' + (grid[x][y] >= grid[n][m]);
                        if (k - ans <= p[idx])
                            p[idx] = k;
                        else
                            p[idx] += ans;
                    }
                    else
                    {
                        if (vt[x][y] != l)
                            vec[grid[x][y] - 'a'].push_back({x, y});
                        if (k - dem <= de[x][y])
                            de[x][y] = k;
                        else
                            de[x][y] += dem;
                        int ans = 0;
                        if (k / dem >= dp[x][y])
                            ans = dem * dp[x][y];
                        else
                            ans = k;
                        int idx = grid[x][y] - 'a';
                        if (k - ans <= p[idx])
                            p[idx] = k;
                        else
                            p[idx] += ans;
                    }
                    vt[x][y] = l;
                }
            }
        }

        for (int i = 0; i < 27; i++)
        {
            if (k - p[i] <= 0)
            {
                cout << t[i];
                for (ii ii_node : vec[i])
                    qu.push({de[ii_node.fi][ii_node.se], ii_node});
                break;
            }
            else
                k -= p[i];
        }

        for (int i = 0; i < 27; i++)
        {
            for (ii cur : vec[i])
            {
                de[cur.fi][cur.se] = 0;
            }
        }
    }
}

void solve()
{

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    while (q--)
    {
        int x;
        cin >> x;
        bfs(x);
        cout << endl;
    }
}

main()
{
    skibidi;
    file("ducvodichworldcup");
    cin >> theta;
    solve();
}
/* I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/