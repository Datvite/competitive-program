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
const int MOD = 998244353;
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
int n, a[N], ans = 0, m;
map<int, vector<int>> val;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        val[a[i]].push_back(i);
    }
    int cur = (n * (n + 1) / 2) % MOD;
    int sum = ((m % MOD) * ((m + 1) % MOD) / 2) % MOD;
    int ans = (cur * sum) % MOD;
    for (auto it : val)
    {
        vector<int> vec = it.se;
        int tmp = 0;
        int last = 0;
        for (int id : vec)
        {
            int len = id - last - 1;
            tmp = (tmp + len * (len + 1) / 2) % MOD;
            last = id;
        }
        int tmp2 = n - last;
        tmp2 = (tmp2 * (tmp2 + 1) / 2) % MOD;
        tmp = add(tmp, tmp2);
        int cnt = sub(cur, tmp);
        ans = sub(ans, mul(cnt, it.fi));
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("HAPPYPAR");
    cin >> n >> m;
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
