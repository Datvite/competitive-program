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
int n, a[N], b[N], pa[N], pb[N], res = 0, ans = 0;
unordered_map<int, int> mp;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1)
            pa[i] = max(pa[i - 1], a[i]);
        mp[a[i]]++;
    }
    pa[1] = a[1];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (i > 1)
            pb[i] = max(pb[i - 1], b[i]);
        if (i > 1) mp[b[i]]++;
    }
    pb[1] = b[1];
    for (int i = 2; i <= n; i++)
    {
        int id = upper_bound(pb + 2, pb + n + 1, pa[i]) - (pb + 2);
        mp[pa[i]] += id; 
    }
for (int j = 2; j <= n; j++)
    {
        int id = lower_bound(pa + 2, pa + n + 1, pb[j]) - (pa + 2);
        mp[pb[j]] += id;
    }
    for (auto x : mp)
    {
        if (x.se > res)
        {
            res = x.se;
            ans = x.fi;
        }
        else if (x.se == res)
        {
            ans = max(ans, x.fi);
        }
    }
    cout << ans << " " << res << endl;
}
main()
{
    skibidi;
    file("");
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
