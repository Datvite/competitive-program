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
string str;
int ans = 0;
struct KMP
{
    vector<int> pi;
    void build(const string &s)
    {
        int n = s.size() - 1;
        pi.assign(n + 1, 0);
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
    }
};
void solve()
{
    int n = str.size();
    str = ' ' + str;
    KMP kmp;
    for (int i = 1; i <= n; i++)
    {
        string str1 = " ";
        for (int j = i; j >= 1; j--)
            str1 += str[j];
        kmp.build(str1);
        ans += (n - i + 1) - *max_element(all(kmp.pi));
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
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
