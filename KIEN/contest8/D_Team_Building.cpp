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
const int N = 1e5 + 69;
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
int n, p, k, bf[(1 << 7) + 1], cur[(1 << 7) + 1];
pair<int, vector<int>> a[N];
bool cmp(pair<int, vector<int>> x, pair<int, vector<int>> y)
{
    return x.fi > y.fi;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
        {
            int x;
            cin >> x;
            a[i].se.push_back(x);
        }
    sort(a + 1, a + n + 1, cmp);
    memset(bf, -0x3f, sizeof(bf));
    memset(cur, -0x3f, sizeof(cur));
    bf[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < (1 << p); mask++)
        {
            if ((i - 1) - __builtin_popcount(mask) < k)
                cur[mask] = max(cur[mask], bf[mask] + a[i].fi);
            else
                cur[mask] = max(cur[mask], bf[mask]);
            for (int j = 0; j < p; j++)
            {
                if (!(mask & (1 << j)))
                    cur[mask | (1 << j)] = max(cur[mask | (1 << j)], bf[mask] + a[i].se[j]);
            }
        }
        for (int mask = 0; mask < (1 << p); mask++)
            bf[mask] = cur[mask];
    }
    cout << cur[(1 << p) - 1];
}
main()
{
    skibidi;
    file("");
    cin >> n >> p >> k;
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
