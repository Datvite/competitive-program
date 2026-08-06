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
int n, m, s, t, k;
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
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
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
void solve()
{
    Matrix cur(n, n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cur.a[u - 1][v - 1]++;
    }
    Matrix ans = cur.power(k);
    cout << ans.a[s - 1][t - 1] << endl;
}
main()
{
    skibidi;
    file("LANGTHANG");
    cin >> n >> m >> s >> t >> k;
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
