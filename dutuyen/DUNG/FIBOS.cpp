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
int n, a[N];
struct Matrix
{
    int x[2][2];

    Matrix() {}

    Matrix(int a[2][2])
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                x[i][j] = a[i][j];
            }
        }
    }

    Matrix operator * (const Matrix &b) const
    {
        Matrix c;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c.x[i][j] = 0;

                for (int k = 0; k < 2; k++)
                {
                    c.x[i][j] = add(
                        c.x[i][j],
                        mul(x[i][k], b.x[k][j])
                    );
                }
            }
        }

        return c;
    }

    friend Matrix operator ^ (const Matrix &a, const int &b)
    {
        if (b == 1)
            return a;

        Matrix c = (a ^ (b / 2));

        if (b & 1)
            return c * c * a;

        return c * c;
    }
};
void solve()
{
    Matrix A;
    A.x[0][0] = 1;
    A.x[0][1] = 1;
    A.x[1][0] = 1;
    A.x[1][1] = 0;
    Matrix C = (A ^ (n + 2));
    cout << C.x[0][0] - 1;
}
main()
{
    skibidi;
    file("FIBOS");
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
