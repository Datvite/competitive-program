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
int n, m, k, q, ans = 0;
int par[N][N];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            par[i][j] = j;
        }
    }
}

int acs(int x, int y)
{
    if (par[x][y] == y)
        return y;
    return par[x][y] = acs(x, par[x][y]);
}

void solve()
{
    init();
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int minnx = max(1LL, x - k);
        int maxnx = min(n, x + k);
        for (int i = minnx; i <= maxnx; i++)
        {
            int c = k - abs(i - x);
            int minny = max(1LL, y - c);
            int maxny = min(m, y + c);
            int j = acs(i, minny);
            while (j <= maxny)
            {
                ans++;
                par[i][j] = j + 1;
                j = acs(i, j);
            }
        }
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("REDSTONE");
    cin >> n >> m >> k >> q;
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
