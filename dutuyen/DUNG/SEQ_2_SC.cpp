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
int n, a[N], m, b[N], ansS = 0, ansE = 0, ansG = 0;
vector<int> vals;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
    {
        int sum = 0;
        for (int j = i; j <= m; j++)
        {
            sum += b[j];
            vals.push_back(sum);
        }
    }
    sort(vals.begin(), vals.end());
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            auto bounds = equal_range(vals.begin(), vals.end(), sum);
            ansS += (bounds.fi - vals.begin());
            ansE += (bounds.se - bounds.fi);
            ansG += (vals.end() - bounds.se);
        }
    }
    cout << ansG << " " << ansE << " " << ansS << endl;
}
main()
{
    skibidi;
    file("SEQ2SC");
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