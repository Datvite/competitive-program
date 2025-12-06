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
int n, k, a[N];
deque<int> dqmin, dqmax;
void solve()
{
    // max ai - min ai <= k sum all l and r
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, ans = 0;
    for (int r = 1; r <= n; r++)
    {
        while (!dqmin.empty() && a[dqmin.back()] >= a[r])
            dqmin.pop_back();
        dqmin.push_back(r);
        while (!dqmax.empty() && a[dqmax.back()] <= a[r])
            dqmax.pop_back();
        dqmax.push_back(r);
        while (a[dqmax.front()] - a[dqmin.front()] > k)
        {
            if (dqmin.front() == l)
                dqmin.pop_front();
            if (dqmax.front() == l)
                dqmax.pop_front();
            l++;
        }
        int len = r - l + 1;
        ans += len * (len + 1) / 2;
    }
    cout << ans << endl;
}
main()
{
    skibidi;
    file("SEGVAL");
    cin >> n >> k;
    solve();
}
