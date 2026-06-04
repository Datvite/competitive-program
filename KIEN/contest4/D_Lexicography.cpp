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
int n, l, k, a[N];
string str, res[N];
void solve()
{
    sort(all(str));
    int id = 1, cnt = 0;
    for (int i = 1; i <= l; i++)
    {
        for (int j = id; j <= k; j++)
            res[j] += str[cnt++];
        while (id < k && res[id].back() != res[k].back())
            id++;
    }
    for (int i = 1; i <= n; i++)
        while (res[i].size() < l)
            res[i] += str[cnt++];
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n >> l >> k;
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
