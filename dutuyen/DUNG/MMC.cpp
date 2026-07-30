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
int norm(int x)
{
    x %= MOD;
    if (x < 0)
        x += MOD;
    return x;
}
int add(int a, int b)
{
    return norm(a + b);
}
int mul(int a, int b)
{
    return norm(norm(a) * norm(b));
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int t, n, a[N];
struct Matrix
{
    std::vector<std::vector<long long>> a;
    int r, c;

    Matrix(int r, int c, bool is_identity = false) : r(r), c(c)
    {
        a.assign(r, std::vector<long long>(c, 0));
        if (is_identity)
        {
            for (int i = 0; i < std::min(r, c); i++)
                a[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix res(r, other.c);
        for (int i = 0; i < r; i++)
        {
            for (int k = 0; k < c; k++)
            {
                if (a[i][k] == 0)
                    continue;
                for (int j = 0; j < other.c; j++)
                {
                    res.a[i][j] = add(res.a[i][j], mul(a[i][k], other.a[k][j]));
                }
            }
        }
        return res;
    }

    Matrix power(long long p)
    {
        Matrix res(r, c, true);
        Matrix base = *this;
        while (p > 0)
        {
            if (p & 1)
                res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    cin >> n;
    Matrix A(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> A.a[i][j];
            A.a[i][j] = norm(A.a[i][j]);
        }
    Matrix B(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> B.a[i][j];
            B.a[i][j] = norm(B.a[i][j]);
        }
    Matrix C(n, 1);
    for (int i = 0; i < n; i++)
        C.a[i][0] = rng() % MOD;
    Matrix D(n, 1);
    D = A * C;
    Matrix D1(n, 1);
    D1 = A * D;
    Matrix D2(n, 1);
    D2 = A * D1;
    Matrix B2(n, 1);
    B2 = B * C;
    for (int i = 0; i < n; i++)
        if (D2.a[i][0] != B2.a[i][0])
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
}
main()
{
    skibidi;
    file("MMC");
    cin >> t;
    while (t--)
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
