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
const int MOD = 10;
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
int n, k, a[N];
struct Matrix
{
    int x[100][100];
    Matrix() {}
    Matrix(int a[N][N])
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                x[i][j] = a[i][j];
            }
        }
    }
    Matrix operator*(const Matrix &b) const
    {
        Matrix c;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c.x[i][j] = 0;

                for (int k = 1; k <= n; k++)
                {
                    c.x[i][j] = add(
                        c.x[i][j],
                        mul(x[i][k], b.x[k][j]));
                }
            }
        }
        return c;
    }
    Matrix operator+(const Matrix &b) const
    {
        Matrix c;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c.x[i][j] = add(x[i][j], b.x[i][j]);
            }
        }
        return c;
    }
};
Matrix power(Matrix a, int p)
{
    Matrix res;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res.x[i][j] = (i == j);
    Matrix base = a;
    while (p > 0)
    {
        if (p & 1) res = res * base;
        base = base * base;
        p >>= 1;
    }
    return res;
}
Matrix cal(Matrix A, int n)
{
    if (n == 1)
        return A;
    if (n & 1)
        return cal(A, n - 1) + power(A, n);
    Matrix cur = cal(A, n / 2);
    return (cur * power(A, n / 2)) + cur;
}
void solve()
{
    Matrix A;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                cin >> A.x[i][j];
                A.x[i][j] %= MOD;
            }
    Matrix ans = cal(A, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans.x[i][j] << " ";
        cout << endl;
    }
}
main()
{
    skibidi;
    file("Matrix");
    cin >> n >> k;
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
