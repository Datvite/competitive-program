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
int n, m, a[N], b[N], c[N], d[N], e[N], ans = 0;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
        c[i] = a[i + 1] - a[i];
    for (int i = 1; i < m; i++)
        d[i] = b[i + 1] - b[i];
    for (int i = 1; i < m; i++)
        e[i] = d[i];
    e[m] = -1e18;
    for (int i = 1; i < n; i++)
        e[m + i] = c[i];
    vector<int> pi;
    pi.assign(n + m + 2, 0);
    for (int i = 2; i <= n + m - 1; i++)
    {
        int j = pi[i - 1];
        while (j >= 1 && e[j + 1] != e[i])
            j = pi[j];
        if (e[j + 1] == e[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }
    for (int i = 1; i <= n + m - 1; i++)
    {
        //cout << pi[i] << " ";
        if (pi[i] == m - 1)
            ans++;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("");
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
