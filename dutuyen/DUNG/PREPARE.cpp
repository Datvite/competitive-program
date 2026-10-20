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
int n, m, a[N], ans = 0;
vector<int> vec1, vec2;
void backtrack(int id, int sum)
{
    if (id > n / 2)
    {
        vec1.push_back(sum);
        return;
    }
    backtrack(id + 1, (sum + a[id]) % m);
    backtrack(id + 1, sum);
}
void backtrack2(int id, int sum)
{
    if (id > n)
    {
        vec2.push_back(sum);
        return;
    }
    backtrack2(id + 1, (sum + a[id]) % m);
    backtrack2(id + 1, sum);
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    backtrack(1, 0);
    backtrack2(n / 2 + 1, 0);
    sort(all(vec1));
    sort(all(vec2));
    vec1.erase(unique(all(vec1)), vec1.end());
    vec2.erase(unique(all(vec2)), vec2.end());
    for (int x : vec1)
    {
        auto it = lower_bound(all(vec2), m - x);
        if (it != vec2.begin())
        {
            --it;
            ans = max(ans, (x + *it) % m);
            if (ans == m - 1)
            {
                cout << ans << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("PREPARE");
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
