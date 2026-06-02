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
const int N = 4e6 + 69;
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
int t, n, a[N], e[N], weight[N];
struct fight
{
    int sum;
    bool c1, c2, c3;
    int sz;
};
bool cmp(fight a, fight b)
{
    if (a.sz != b.sz)
        return a.sz < b.sz;
    return a.sum < b.sum;
}
fight cases[7];
bool test(int mid)
{
    int c1 = mid, c2 = mid, c3 = mid;
    for (int i = 1; i <= n; i++)
    {
        int target = e[i];
        bool found = 0;
        for (int j = 0; j < 7; j++)
        {
            if (cases[j].sum >= target)
            {
                if (c1 >= cases[j].c1 && c2 >= cases[j].c2 && c3 >= cases[j].c3)
                {
                    c1 -= cases[j].c1;
                    c2 -= cases[j].c2;
                    c3 -= cases[j].c3;
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    cin >> a[1] >> a[2] >> a[3];
    int maxn = a[1] + a[2] + a[3];
    bool check = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
        if (e[i] > maxn)
            check = 0;
    }
    if (!check)
    {
        cout << -1 << endl;
        return;
    }
    sort(e + 1, e + n + 1, greater<int>());
    cases[0] = {a[1], 1, 0, 0, 1};
    cases[1] = {a[2], 0, 1, 0, 1};
    cases[2] = {a[3], 0, 0, 1, 1};
    cases[3] = {a[1] + a[2], 1, 1, 0, 2};
    cases[4] = {a[1] + a[3], 1, 0, 1, 2};
    cases[5] = {a[2] + a[3], 0, 1, 1, 2};
    cases[6] = {a[1] + a[2] + a[3], 1, 1, 1, 3};
    sort(cases, cases + 7, cmp);
    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (test(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("fight");
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
