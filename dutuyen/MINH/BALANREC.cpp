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
int n, m, ans = 0;
const int dif = 5e5;
int mp[N], last[N], timer = 0;
/*void solvenm()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            mp[dif] = 1;
            for (int k = 1; k <= m; k++)
            {
                int cur = sum[j][k] - sum[i - 1][k];
                if (mp[cur + dif] != 0)
                {
                    int id = mp[cur + dif] - 1;
                    ans = max(ans, (j - i + 1) * (k - id));
                }
                else
                    mp[cur + dif] = k + 1;
            }
            mp[dif] = 0;
            for (int k = 1; k <= m; k++)
            {
                int cur = sum[j][k] - sum[i - 1][k];
                mp[cur + dif] = 0;
            }
        }
    }
}
void solvemn()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            mp[dif] = 1;
            for (int k = 1; k <= n; k++)
            {
                int cur = sum[k][j] - sum[k][i - 1];
                if (mp[cur + dif] != 0)
                {
                    int id = mp[cur + dif] - 1;
                    ans = max(ans, (j - i + 1) * (k - id));
                }
                else
                    mp[cur + dif] = k + 1;
            }
            mp[dif] = 0;
            for (int k = 1; k <= n; k++)
            {
                int cur = sum[k][j] - sum[k][i - 1];
                mp[cur + dif] = 0;
            }
        }
    }
}*/
void solve()
{
    vector<vector<int>> val(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> val[i][j];
            if (val[i][j] == 0)
                val[i][j] = -1;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
        }
    if (n < m)
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                timer++;
                mp[dif] = 1;
                last[dif] = timer;
                for (int k = 1; k <= m; k++)
                {
                    int cur = sum[j][k] - sum[i - 1][k];
                    if (last[cur + dif] == timer)
                    {
                        int id = mp[cur + dif] - 1;
                        ans = max(ans, (j - i + 1) * (k - id));
                    }
                    else
                    {
                        mp[cur + dif] = k + 1;
                        last[cur + dif] = timer;
                    }
                }
            }
        }
    else
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j++)
            {
                timer++;
                mp[dif] = 1;
                last[dif] = timer;
                for (int k = 1; k <= n; k++)
                {
                    int cur = sum[k][j] - sum[k][i - 1];
                    if (last[cur + dif] == timer)
                    {
                        int id = mp[cur + dif] - 1;
                        ans = max(ans, (j - i + 1) * (k - id));
                    }
                    else
                    {
                        mp[cur + dif] = k + 1;
                        last[cur + dif] = timer;
                    }
                }
            }
        }
    cout << ans;
}
int main()
{
    skibidi;
    file("");
    cin >> n >> m;
    solve();
    return 0;
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
