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
int t, n, m, k, a[N], ans = 0;
bool mark[N];
struct newyear
{
    int id, x, y, z;
} f[N];
bool cmp(newyear a, newyear b)
{
    return a.x < b.x;
}
void solve()
{
    cin >> n >> m >> k;
    ans = 0;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    int sumy = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].x >> f[i].y >> f[i].z;
        mark[i] = 0;
        f[i].id = i;
        sumy += f[i].y;
    }
    k -= sumy;
    if (k < 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(f + 1, f + n + 1, cmp);
    int id = 1;
    set<ii> s;
    for (int i = 1; i <= m; i++)
    {
        while (id <= n && f[id].x <= a[i])
        {
            s.insert({f[id].z - f[id].y, f[id].id});
            id++;
        }
        if (!s.empty())
        {
            ii cur = *s.rbegin();
            s.erase(s.find(cur));
            mark[cur.se] = 1;
            ans++;
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (!mark[f[i].id])
            v.push_back(f[i].z - f[i].y);
    sort(v.begin(), v.end());
    for (int x : v)
    {
        if (k >= x)
        {
            k -= x;
            ans++;
        }
    }
    cout << ans << endl;
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
