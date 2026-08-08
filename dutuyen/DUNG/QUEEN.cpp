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
int n, m, ans[N][N];
char ch[N][N];
void cal_diagram1(int x, int y)
{
    for (int i = x, j = y; i <= n && j <= m;)
    {
        if (ch[i][j] == '.')
        {
            int ki = i, kj = j;
            while (ki <= n && kj <= m && ch[ki][kj] == '.')
            {
                ki++;
                kj++;
            }
            int len = ki - i;
            for (int x = 0; x < len; x++)
                ans[i + x][j + x] += len;
            i = ki;
            j = kj;
        }
        else
        {
            i++;
            j++;
        }
    }
}
void cal_diagram2(int x, int y)
{
    for (int i = x, j = y; i <= n && j >= 1;)
    {
        if (ch[i][j] == '.')
        {
            int ki = i, kj = j;
            while (ki <= n && kj >= 1 && ch[ki][kj] == '.')
            {
                ki++;
                kj--;
            }
            int len = ki - i;
            for (int x = 0; x < len; x++)
                ans[i + x][j - x] += len;
            i = ki;
            j = kj;
        }
        else
        {
            i++;
            j--;
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ch[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;)
        {
            if (ch[i][j] == '.')
            {
                int k = j;
                while (k <= m && ch[i][k] == '.')
                    k++;
                int len = k - j;
                for (int x = j; x < k; x++)
                    ans[i][x] += len;
                j = k;
            }
            else
                j++;
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n;)
        {
            if (ch[i][j] == '.')
            {
                int k = i;
                while (k <= n && ch[k][j] == '.')
                    k++;
                int len = k - i;
                for (int x = i; x < k; x++)
                    ans[x][j] += len;
                i = k;
            }
            else
                i++;
        }
    }
    for (int i = 1; i <= n; i++)
        cal_diagram1(i, 1);
    for (int j = 2; j <= m; j++)
        cal_diagram1(1, j);
    for (int i = 1; i <= n; i++)
        cal_diagram2(i, m);
    for (int j = 1; j < m; j++)
        cal_diagram2(1, j);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ch[i][j] == '.')
                cout << ans[i][j] - 3 << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    skibidi;
    file("queen");
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
