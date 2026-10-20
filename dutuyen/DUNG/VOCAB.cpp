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
const int MOD = 1e9 + 9;
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
int n, a[N], cnt = 0;
string str[4];
vector<char> vec;
int backtrack(int id)
{
    if (id > cnt)
    {
        int i = 0;
        string tmp1 = "", tmp2 = "", tmp3 = "";
        for (auto ch : str[1])
        {
            if (ch == '?')
                tmp1 += vec[i++];
            else
                tmp1 += ch;
        }
        for (auto ch : str[2])
        {
            if (ch == '?')
                tmp2 += vec[i++];
            else
                tmp2 += ch;
        }
        for (auto ch : str[3])
        {
            if (ch == '?')
                tmp3 += vec[i++];
            else
                tmp3 += ch;
        }
        return tmp1 < tmp2 && tmp2 < tmp3;
    }
    int res = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        vec.push_back(c);
        res += backtrack(id + 1);
        res %= MOD;
        vec.pop_back();
    }
    return res % MOD;
}
void solve()
{
    for (auto ch : str[1])
        if (ch == '?')
            cnt++;
    for (auto ch : str[2])
        if (ch == '?')
            cnt++;
    for (auto ch : str[3])
        if (ch == '?')
            cnt++;
    cout << backtrack(1) << endl;
}
main()
{
    skibidi;
    file("VOCAB");
    cin >> str[1] >> str[2] >> str[3];
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
