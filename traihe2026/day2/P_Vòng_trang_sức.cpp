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
int n, a[N], c[28][28], ans = 0;
string s[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
    {
        vector<iii> tmp;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (c[ch - 'a'][s[i][0] - 'a'])
            {
                c[ch - 'a'][s[i][s[i].size() - 1] - 'a'] = max(c[ch - 'a'][s[i][s[i].size() - 1] - 'a'], c[ch - 'a'][s[i][0] - 'a'] + (long long)s[i].size());
            }
        }
            c[s[i][0] - 'a'][s[i][s[i].size() - 1] - 'a'] = max(c[s[i][0] - 'a'][s[i][s[i].size() - 1] - 'a'], (long long)s[i].size());
    }
    for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
    {
        ans = max(ans, c[ch1 - 'a'][ch1 - 'a']);
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("puzzles");
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
