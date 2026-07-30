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
int n, ans = 0;
vector<int> v1, v2;
ii a[N];
void backtrack1(int id, int M)
{
    if (M > 1e9)
        return;
    if (id > n / 2)
    {
        v1.push_back(M);
        return;
    }
    backtrack1(id + 1, M);
    int s = 1;
    for (int i = 1; i <= a[id].se; i++)
    {
        s *= a[id].fi;
        if (s > 1e9)
            return;
        backtrack1(id + 1, M * s);
    }
}
void backtrack2(int id, int M)
{
    if (M > 1e9)
        return;
    if (id > n)
    {
        v2.push_back(M);
        return;
    }
    int s = 1;
    backtrack2(id + 1, M);
    for (int i = 1; i <= a[id].se; i++)
    {
        s *= a[id].fi;
        if (s > 1e9)
            return;
        backtrack2(id + 1, M * s);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    random_shuffle(a + 1, a + n + 1);
    backtrack1(1, 1);
    backtrack2(n / 2 + 1, 1);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i = 1; i <= 3; i++)
    {
        int l, r;
        cin >> l >> r;
        ans = 0;
        for (auto x : v2)
        {
            int tmp1, tmp2;
            if (l % x == 0)
                tmp1 = l / x;
            else
                tmp1 = l / x + 1;
            tmp2 = r / x;
            auto id1 = lower_bound(v1.begin(), v1.end(), tmp1);
            auto id2 = upper_bound(v1.begin(), v1.end(), tmp2);
            ans += (id2 - id1);
        }
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("USAB");
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
