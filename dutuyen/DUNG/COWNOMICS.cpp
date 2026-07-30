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
int n, m, ans = 0, wh[N][N], bl[N][N], bit[N];
char ch;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == 'A')
                wh[i][j] = 0;
            else if (ch == 'C')
                wh[i][j] = 1;
            else if (ch == 'G')
                wh[i][j] = 2;
            else if (ch == 'T')
                wh[i][j] = 3;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == 'A')
                bl[i][j] = 0;
            else if (ch == 'C')
                bl[i][j] = 1;
            else if (ch == 'G')
                bl[i][j] = 2;
            else if (ch == 'T')
                bl[i][j] = 3;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            for (int k = j + 1; k <= m; k++)
            {
                for (int b = 0; b <= 64; b++)
                {
                    bit[b] = 0;
                }
                for (int l = 1; l <= n; l++)
                    bit[((wh[l][i] << 4) | (wh[l][j] << 2) | wh[l][k])] = 1;
                bool check = 1;
                for (int l = 1; l <= n; l++)
                {
                    if (bit[((bl[l][i] << 4) | (bl[l][j] << 2) | bl[l][k])])
                    {
                        check = 0;
                        break;
                    }
                }
                if (check)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("COWNOMICS");
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
