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
const int MOD = 2e9 + 11;
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
int n, a[N], ans = 1e18;
string str;
map<int, int> mp;
void solve()
{
    int l = 1, cnt = 0;
    for (int r = 1; r <= n; r++)
    {
        if (mp[str[r]] == 0)
            cnt++;
        mp[str[r]]++;
        while (cnt == 26)
        {
            ans = min(ans, r - l + 1);
            mp[str[l]]--;
            if (mp[str[l]] == 0)
                cnt--;
            l++;
        }
    }
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
    str = " " + str;
    solve();
}
