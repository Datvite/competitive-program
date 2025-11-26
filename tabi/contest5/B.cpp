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
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e5 + 69;
const int BASE = 256;
const int MOD = 123456789;
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
int n, a[N], dp[4][3][2][2][2];
void solve()
{
    dp[0][0][0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int f2 = 0, f3 = 0, f5 = 0, f7 = 0;
        while (a[i] % 2 == 0)
        {
            f2++;
            a[i] /= 2;
        }
        while (a[i] % 3 == 0)
        {
            f3++;
            a[i] /= 3;
        }
        while (a[i] % 5 == 0)
        {
            f5++;
            a[i] /= 5;
        }
        while (a[i] % 7 == 0)
        {
            f7++;
            a[i] /= 7;
        }
        for (int g2 = 0; g2 <= 3; g2++)
            for (int g3 = 0; g3 <= 2; g3++)
                for (int g5 = 0; g5 <= 1; g5++)
                    for (int g7 = 0; g7 <= 1; g7++)
                        dp[g2][g3][g5][g7][i % 2] = 0;
        for (int g2 = 0; g2 <= 3; g2++)
            for (int g3 = 0; g3 <= 2; g3++)
                for (int g5 = 0; g5 <= 1; g5++)
                    for (int g7 = 0; g7 <= 1; g7++)
                    {
                        int c2 = min(3LL, g2 + f2);
                        int c3 = min(2LL, g3 + f3);
                        int c5 = min(1LL, g5 + f5);
                        int c7 = min(1LL, g7 + f7);
                        dp[g2][g3][g5][g7][i % 2] = add(dp[g2][g3][g5][g7][i % 2], dp[g2][g3][g5][g7][(i - 1) % 2]);
                        dp[c2][c3][c5][c7][i % 2] = add(dp[c2][c3][c5][c7][i % 2], dp[g2][g3][g5][g7][(i - 1) % 2]);
                    }
    }
    cout << dp[3][2][1][1][n % 2];
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
