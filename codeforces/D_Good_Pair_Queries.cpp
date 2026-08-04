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
int t, n, q, a[N], cnt00[N], cnt01[N], cnt10[N], cnt11[N];
string str1, str2;
void solve()
{
    cin >> n >> q;
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    for (int i = 1; i <= n; i++)
    {
        cnt00[i] = cnt00[i - 1];
        cnt01[i] = cnt01[i - 1];
        cnt10[i] = cnt10[i - 1];
        cnt11[i] = cnt11[i - 1];
        if (str1[i] == '0' && str2[i] == '0')
            cnt00[i] += 1;
        else if (str1[i] == '0' && str2[i] == '1')
            cnt01[i] += 1;
        else if (str1[i] == '1' && str2[i] == '0')
            cnt10[i] += 1;
        else
            cnt11[i] += 1;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans00 = cnt00[r] - cnt00[l - 1];
        int ans01 = cnt01[r] - cnt01[l - 1];
        int ans10 = cnt10[r] - cnt10[l - 1];
        int ans11 = cnt11[r] - cnt11[l - 1];
        if (ans00 + ans11 >= abs(ans10 - ans01))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
