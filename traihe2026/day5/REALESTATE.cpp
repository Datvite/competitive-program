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
int n, a[N], m, k;
char cur[N];
bool check(char ch, int id)
{
    for (int i = 1; i < id; i++)
    {
        if (cur[i] == ch)
        {
            int dif = abs(id - i);
            if (dif <= a[i] || dif <= a[id])
                return false;
        }
    }
    return true;
}
int cnt_ways(int id)
{
    if (id > n)
        return 1;
    int cnt = 0;
    for (int c = 1; c <= m; c++)
    {
        if (check(char(c + 'a' - 1), id))
        {
            cur[id] = char(c + 'a' - 1);
            cnt += cnt_ways(id + 1);
            cur[id] = 0;
            if (cnt > 2e18)
                cnt = 2e18;
        }
    }
    return cnt;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int total = cnt_ways(1);
    if (k >= total)
    {
        cout << -1;
        return;
    }
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        for (int c = 1; c <= m; c++)
        {
            int ways = 0;
            if (check(char(c + 'a' - 1), i))
            {
                cur[i] = char(c + 'a' - 1);
                ways += cnt_ways(i + 1);
                if (ways <= k)
                {
                    ans += char(c + 'a' - 1);
                    break;
                }
                else
                {
                    k -= ways;
                    cur[i] = 0;
                }
            }
        }
    }
    cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> n >> m >> k;
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
