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
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
/*int add(int a, int b)
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
}*/
int n, b[N], k, h1[N], h2[N], p1[N], p2[N], ans = 0;
string str;
char a[N];
unordered_set<long long> st;
int get1(int l, int r)
{
    return (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
}
int get2(int l, int r)
{
    return (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
}
void solve()
{
    for (int i = 1; i <= 26; i++)
        cin >> a[i];
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        if (a[str[i] - 'a' + 1] == '0')
            b[i]++;
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    /*for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;*/
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int x = get1(i, j);
            int y = get2(i, j);
            int key = (1LL * x << 32) ^ y;
            if (b[j] - b[i - 1] <= k && st.find(key) == st.end())
            {
                st.insert(key);
                // cout << i << " " << j << endl;
                ans++;
            }
        }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
    str = " " + str;
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p1[i] = (p1[i - 1] * BASE) % MOD1;
        p2[i] = (p2[i - 1] * BASE) % MOD2;
    }
    for (int i = 1; i <= n; i++)
    {
        h1[i] = (h1[i - 1] * BASE + str[i]) % MOD1;
        h2[i] = (h2[i - 1] * BASE + str[i]) % MOD2;
    }
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
