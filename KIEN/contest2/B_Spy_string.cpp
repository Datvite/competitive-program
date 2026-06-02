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
int t, n, m, a[N];
string s[15], ans;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    ans = s[1];
    for (int i = 1; i <= m; i++)
    {
        char ch = ans[i - 1];
        for (int j = 'a'; j <= 'z'; j++)
        {
            ans[i - 1] = (char)j;
            bool valid = true;
            for (int k = 1; k <= n; k++)
            {
                int dif = 0;
                for (int l = 1; l <= m; l++)
                    if (s[k][l - 1] != ans[l - 1])
                        dif++;
                if (dif > 1)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                cout << ans << endl;
                return;
            }
        }
        ans[i - 1] = ch;
    }
    cout << -1 << endl;
}
main()
{
    skibidi;
    file("");
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
