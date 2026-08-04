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
int n, m, a[N], b[N], f[N], ans1 = 0, ans2 = 0, ans = 0, cost[N], ansc = 1e18;
vector<ii> pizzas[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int x, mask, y;
        cin >> x;
        mask = 0;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            mask |= (1 << (y - 1));
        }
        f[mask]++;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int mask = 0; mask < (1 << 9); mask++)
        {
            if (mask & (1 << i))
            {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> cost[i] >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> y;
            b[i] |= (1 << (y - 1));
        }
        pizzas[b[i]].push_back({cost[i], i});
    }
    for (int mask = 0; mask < (1 << 9); mask++)
    {
        sort(all(pizzas[mask]));
    }
    for (int mask1 = 0; mask1 < (1 << 9); mask1++)
    {
        for (int mask2 = 0; mask2 < (1 << 9); mask2++)
        {
            if (mask1 == mask2)
            {
                if (pizzas[mask1].size() >= 2)
                {
                    if (f[mask1] > ans || (f[mask1] == ans && pizzas[mask1][0].fi + pizzas[mask1][1].fi < ansc))
                    {
                        ans = f[mask1];
                        ans1 = pizzas[mask1][0].se;
                        ans2 = pizzas[mask1][1].se;
                        ansc = pizzas[mask1][0].fi + pizzas[mask1][1].fi;
                    }
                }
            }
            else
            {
                int mask = mask1 | mask2;
                if (pizzas[mask1].size() && pizzas[mask2].size())
                {
                    if (f[mask] > ans || (f[mask] == ans && pizzas[mask1][0].fi + pizzas[mask2][0].fi < ansc))
                    {
                        ans = f[mask];
                        ans1 = pizzas[mask1][0].se;
                        ans2 = pizzas[mask2][0].se;
                        ansc = pizzas[mask1][0].fi + pizzas[mask2][0].fi;
                    }
                }
            }
        }
    }
    if (ans1 > ans2)
    swap(ans1, ans2);
    cout << ans1 << " " << ans2 << endl;
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
