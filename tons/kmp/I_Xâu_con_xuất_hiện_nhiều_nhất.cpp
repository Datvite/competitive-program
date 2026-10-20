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
const int N = 1e7 + 69;
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
string s, t;
struct KMP
{
    vector<int> pi;
    vector<vector<int>> aut;
    void build(const string &s)
    {
        int n = s.size() - 1;
        pi.assign(n + 1, 0);
        aut.assign(n + 1, vector<int>(26, 0));
        for (int i = 2; i <= n; i++)
        {
            int j = pi[i - 1];
            while (j >= 1 && s[j + 1] != s[i])
                j = pi[j];
            if (s[j + 1] == s[i])
                pi[i] = j + 1;
            else
                pi[i] = 0;
        }

        for (int i = 0; i <= n; i++)
        {
            for (int c = 0; c < 26; c++)
            {
                if (i < n && s[i + 1] - 'a' == c)
                    aut[i][c] = i + 1;
                else
                    aut[i][c] = aut[pi[i]][c];
            }
        }
    }
};
int ans = 0;
void solve()
{
    int n = s.size();
    s = ' ' + s;
    int m = t.size();
    t = ' ' + t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e18));
    dp[0][0] = 0;
    KMP kmp;
    kmp.build(t);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (s[i + 1] == '?')
            {
                for (int c = 0; c < 26; c++)
                {
                    dp[i + 1][kmp.aut[j][c]] = max(dp[i + 1][kmp.aut[j][c]], dp[i][j] + (kmp.aut[j][c] == m));
                }
            }
            else
            {
                int c = s[i + 1] - 'a';
                dp[i + 1][kmp.aut[j][c]] = max(dp[i + 1][kmp.aut[j][c]], dp[i][j] + (kmp.aut[j][c] == m));
            }
        }
    }
    for (int j = 0; j <= m; j++)
        ans = max(ans, dp[n][j]);
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
    cin >> s >> t;
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
