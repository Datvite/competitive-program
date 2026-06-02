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
int t, n, a[N], b[N], wait[N], ans = 0;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int vday = 0;
    for (int i = 1; i <= n; i++)
    {
        wait[1]++;
        vday++;
        if (a[i] == b[i])
        {
            wait[a[i] + 1] += wait[a[i]];
            wait[a[i]] = 0;
        }
        else
        {
            vday -= wait[a[i]];
            wait[a[i]] = 0;
            vday -= wait[b[i]];
            wait[b[i]] = 0;
        }
        ans += vday;
    }
    cout << ans << endl;
    wait[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        wait[a[i]] = 0;
        wait[b[i]] = 0;
        wait[a[i] + 1] = 0;
        wait[b[i] + 1] = 0;
    }
    ans = 0;
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
