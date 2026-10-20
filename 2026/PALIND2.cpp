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
int n, ans = 1, cnt = 0;
bool f[N][N];
void solve()
{
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        f[i][i] = true;
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (s[i] == s[j] && (j == i + 1 || f[i + 1][j - 1]))
            {
                f[i][j] = true;
                if (abs(i - j) + 1 > ans)
                {
                    ans = abs(i - j) + 1;
                }
            }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (f[i][j] && abs(i - j) + 1 == ans)
                cnt++;
    cout << ans << endl << cnt;
}
main()
{
    skibidi;
    file("PALIND2");
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
