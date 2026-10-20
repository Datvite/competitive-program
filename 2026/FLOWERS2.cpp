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
int n, cur = 0, ans = 0, delta;
unordered_map<string, int> cnt;
struct flower
{
    string name;
    int pos;
} a[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i].pos >> a[i].name;
    int l = 1;
    sort(a + 1, a + n + 1, [](const flower &x, const flower &y)
         {
             return x.pos < y.pos;
         });
    for (int r = 1; r <= n; r++)
    {
        if (cnt[a[r].name] == 0)
            cur++;
        cnt[a[r].name]++;
        while (a[r].pos - a[l].pos > delta)
        {
            cnt[a[l].name]--;
            if (cnt[a[l].name] == 0)
                cur--;
            l++;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("FLOWERS");
    cin >> n >> delta;
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
