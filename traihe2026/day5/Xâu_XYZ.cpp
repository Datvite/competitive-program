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
int C[35][35];
void nCr()
{
    for (int i = 0; i <= 30; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
int cal(int m, int n, int p)
{
    if (m < 0 || n < 0 || p < 0)
        return 0;
    return C[m + n + p][m] * C[n + p][n];
}
void solve()
{
    int m, n, p;
    cin >> m >> n >> p;
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int curm = m, curn = n, curp = p;
        int len = m + n + p;
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            int X = cal(curm - 1, curn, curp);
            if (curm > 0 && k <= X)
            {
                ans += 'X';
                curm--;
                continue;
            }
            if (curm > 0)
                k -= X;
            int Y = cal(curm, curn - 1, curp);
            if (curn > 0 && k <= Y)
            {
                ans += 'Y';
                curn--;
                continue;
            }
            if (curn > 0)
                k -= Y;
            ans += 'Z';
            curp--;
        }
        cout << ans << endl;
    }
}

main()
{
    skibidi;
    file("");
    nCr();
    solve();
}
/*
    I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/