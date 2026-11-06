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
const int N = 3e3 + 69;
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
int n, a[N], f[N][N];
string str;
void solve()
{
    n = str.size();
    for (int i = n - 1; i >= 0; i--)
    {
        f[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
                f[i][j] = f[i + 1][j - 1] + 2;
            else
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        }
    }
    string res = "";
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (i == j)
        {
            res += str[i];
            break;
        }
        if (str[i] == str[j])
        {
            res += str[i];
            i++;
            j--;
        }
        else if (f[i + 1][j] > f[i][j - 1])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << f[0][n - 1] << endl;
    string ans = res;
    for (int k = f[0][n - 1] - res.size() - 1; k >= 0; k--)
        ans += res[k];
    cout << ans << endl;
}
main()
{
    skibidi;
    file("PALIND4");
    cin >> str;
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
