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
const int MOD = 111539786;
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
            for (int c = 0; c < 2; c++)
            {
                if (i < n && s[i + 1] - '0' == c)
                    aut[i][c] = i + 1;
                else
                    aut[i][c] = aut[pi[i]][c];
            }
        }
    }
};
string cur = "";
string str[15];
int ans = 0;
void backtrack(int id)
{
    if (id > n)
    {
        bool check = 1;
        for (int i = 1; i <= k; i++)
        {
            if (cur.find(str[i]) != string::npos)
            {
                check = 0;
                break;
            }
        }
        if (check)
            ans++;
        ans %= MOD;
        return;
    }
    cur += '0';
    backtrack(id + 1);
    cur.pop_back();
    cur += '1';
    backtrack(id + 1);
    cur.pop_back();
}
void sub1()
{
    for (int i = 1; i <= k; i++)
        cin >> str[i];
    backtrack(1);
    cout << ans;
}
string t;
int dp[207][207];
void sub2()
{
    cin >> t;
    int m = t.size();
    KMP kmp;
    t = ' ' + t;
    kmp.build(t);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!dp[i][j])
                continue;
            for (int l = 0; l < 2; l++)
            {
                int c = kmp.aut[j][l];
                if (c < m)
                    dp[i + 1][c] = (dp[i + 1][c] + dp[i][j]) % MOD;
            }
        }
    }
    for (int j = 0; j < m; j++)
        ans = (ans + dp[n][j]) % MOD;
    cout << ans;
}
main()
{
    skibidi;
    file("DNASEQ");
    cin >> n >> k;
    if (n <= 20)
        sub1();
    else
    sub2();
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
