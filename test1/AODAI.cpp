#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout);  \
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
int n, a[N], ans = 0;
multiset<int> s;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    while (!s.empty())
    {
        int tmp = 4;
        auto it = s.upper_bound(tmp);
        if (it != s.begin())
        {
            --it;
            tmp -= *it;
            s.erase(it);
        }
        while (tmp > 0 && !s.empty())
        {
            it = s.upper_bound(tmp);
            if (it == s.begin())
                break;
            --it;
            tmp -= *it;
            s.erase(it);
        }
        ans++;
    }
    cout << ans;
}
main()
{
    skibidi;
    file("aodai");
    cin >> n;
    solve();
}
