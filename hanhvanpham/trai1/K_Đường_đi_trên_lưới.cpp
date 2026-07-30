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
const int N = 300 + 69;
const int inf = 1e18;
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
int m, n, q, theta;
string a[N];
int dp[N][N];
struct node
{
    char ch;
    int nx, ny;
    bool operator<(const node &other) const
    {
        if (ch != other.ch)
            return ch < other.ch;
        if (nx != other.nx)
            return nx < other.nx;

        return ny < other.ny;
    }
};
void solve()
{
    cin >> m;
    cin >> n;
    cin >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int i = m; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i == m && j == n)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = 0;

            if (i < m)
                dp[i][j] = min(inf, dp[i][j] + dp[i + 1][j]);
            if (j < n)
                dp[i][j] = min(inf, dp[i][j] + dp[i][j + 1]);
            if (i < m && j < n)
                dp[i][j] = min(inf, dp[i][j] + dp[i + 1][j + 1]);
        }
    }
    vector<int> k(q);
    for (int i = 0; i < q; i++)
        cin >> k[i];
    for (int qi = 0; qi < q; qi++)
    {
        int kk = k[qi];
        if (kk > dp[1][1])
        {
            cout << "-1\n";
            continue;
        }
        int x = 1, y = 1;
        string ans = "";
        while (true)
        {
            ans.push_back(a[x][y]);

            if (x == m && y == n)
                break;
            vector<node> moves;
            if (x < m)
                moves.push_back({a[x + 1][y], x + 1, y});
            if (y < n)
                moves.push_back({a[x][y + 1], x, y + 1});
            if (x < m && y < n)
                moves.push_back({a[x + 1][y + 1], x + 1, y + 1});
            sort(moves.begin(), moves.end());
            int id = 0;
            while (id < (int)moves.size())
            {
                char c = moves[id].ch;
                int sum = 0;
                int j = id;
                while (j < (int)moves.size() && moves[j].ch == c)
                {
                    sum = min(inf, sum + dp[moves[j].nx][moves[j].ny]);
                    j++;
                }
                if (kk > sum)
                {
                    kk -= sum;
                    id = j;
                    continue;
                }
                while (id < j)
                {
                    if (kk <= dp[moves[id].nx][moves[id].ny])
                    {
                        x = moves[id].nx;
                        y = moves[id].ny;
                        break;
                    }
                    kk -= dp[moves[id].nx][moves[id].ny];
                    id++;
                }
                break;
            }
        }
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("ducvodichworldcup");
    cin >> theta;
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
