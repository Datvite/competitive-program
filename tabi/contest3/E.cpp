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
const int N = 1e2 + 69;
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
int t;
int n, a[N], b[N], sum = 101 * 101 / 2, dp[N][N * 101], s = 0, val = 0;
vector<int> v1, v2;
void reset()
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = 0;
    v1.clear();
    v2.clear();
    s = 0;
    val = 0;
}
void solve()
{
    reset();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        s += b[i];
    }
    dp[1][0] = 1;
    sum = n * 100;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i][j])
            {
                if (j + a[i] <= sum)
                    dp[i + 1][j + a[i]] = 1;
                if (j + b[i] <= sum)
                    dp[i + 1][j + b[i]] = 1;
            }
        }
    int mindiff = 1e18;
    for (int j = 0; j <= sum; j++)
        if (dp[n + 1][j])
        {
            int diff = abs(s - 2 * j);
            if (diff < mindiff)
            {
                mindiff = diff;
                val = j;
            }
        }
    // Truy vet
    int curr = val;
    for (int i = n; i >= 1; i--)
    {
        if (curr - a[i] >= 0 && dp[i][curr - a[i]])
        {
            v1.push_back(a[i]);
            v2.push_back(b[i]);
            curr -= a[i];
        }
        else
        {
            v2.push_back(a[i]);
            v1.push_back(b[i]);
            curr -= b[i];
        }
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += (v1[i] + v1[j]) * (v1[i] + v1[j]) + (v2[i] + v2[j]) * (v2[i] + v2[j]);
    cout << res << endl;
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
        solve();
}
