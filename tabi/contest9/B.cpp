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
int t, n, a[N], sum = 0;
map<int, int> mp;
void solve()
{
    mp.clear();
    sum = 0;
    cin >> n;
    for (int i = 1; i <= n + 2; i++)
    {
        cin >> a[i];
    }
    int x = 0;
    sort(a + 1, a + n + 3);
    mp[a[n + 1]]++;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    if (mp[sum])
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        goto end;
    }
    mp[a[n + 1]]--;
    mp[a[n + 2]]++;
    sum += a[n + 1];
    for (int i = 1; i <= n + 1; i++)
    {
        int z = sum - a[i];
        if (mp[z])
        {
            x = i;
            break;
        }
    }
    if (x == 0)
        cout << -1;
    else
    {
        for (int i = 1; i <= n + 1; i++)
        {
            if (i != x)
                cout << a[i] << " ";
        }
    }
end:
    cout << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
