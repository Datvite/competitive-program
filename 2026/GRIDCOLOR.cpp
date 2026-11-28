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
int n, m, k;
string h[N], v[N];
int c[N][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n - 1; i++)
        cin >> v[i];
    if (k == 1)
    {
        int cntE = 0;
        int tot = n * (m - 1) + (n - 1) * m;
        for (int i = 1; i <= n; i++)
        {
            for (char ch : h[i])
            {
                if (ch == 'E')
                    cntE++;
            }
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (char ch : v[i])
            {
                if (ch == 'E')
                    cntE++;
            }
        }
        if (4 * cntE < 3 * tot)
        {
            cout << -1 << endl;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << 1 << (j == m ? "" : " ");
            cout << endl;
        }
        return;
    }
    if (m >= n)
    {
        for (int i = 1; i <= n; i++)
        {
            c[i][1] = 1;
            for (int j = 2; j <= m; j++)
            {
                if (h[i][j - 2] == 'E')
                    c[i][j] = c[i][j - 1];
                else
                    c[i][j] = 3 - c[i][j - 1];
            }
            if (i >= 2)
            {
                int match = 0;
                for (int j = 1; j <= m; j++)
                {
                    if ((v[i - 1][j - 1] == 'E' && c[i][j] == c[i - 1][j]) ||
                        (v[i - 1][j - 1] == 'N' && c[i][j] != c[i - 1][j]))
                        match++;
                }
                if (2 * match < m)
                {
                    for (int j = 1; j <= m; j++)
                        c[i][j] = 3 - c[i][j];
                }
            }
        }
    }
    else
    {
        for (int j = 1; j <= m; j++)
        {
            c[1][j] = 1;
            for (int i = 2; i <= n; i++)
            {
                if (v[i - 1][j - 1] == 'E')
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = 3 - c[i - 1][j];
            }
            if (j >= 2)
            {
                int match = 0;
                for (int i = 1; i <= n; i++)
                {
                    if ((h[i][j - 2] == 'E' && c[i][j] == c[i][j - 1]) ||
                        (h[i][j - 2] == 'N' && c[i][j] != c[i][j - 1]))
                        match++;
                }
                if (2 * match < n)
                {
                    for (int i = 1; i <= n; i++)
                        c[i][j] = 3 - c[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << c[i][j] << (j == m ? "" : " ");
        cout << endl;
    }
}
main()
{
    skibidi;
    file("GRIDCOLOR");
    cin >> n >> m >> k;
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
