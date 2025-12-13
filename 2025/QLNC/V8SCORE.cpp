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
const int N = 1e3 + 69;
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
int S, k, n, a[N][N];
vector<int> v;
void Try(int id, int last, int sum)
{
    if (id > k)
    {
        if (sum == S)
        {
            cout << "YES" << endl;
            for (auto x : v)
                cout << x << " ";
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[id][i] >= last && sum + a[id][i] <= S)
        {
            v.push_back(a[id][i]);
            Try(id + 1, a[id][i], sum + a[id][i]);
            v.pop_back();
        }
    }
}
void solve()
{
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= k; i++)
            cin >> a[i][j];
    Try(1, -1, 0);
    cout << "NO";
}
main()
{
    skibidi;
    file("V8SCORE");
    cin >> S >> k >> n;
    solve();
}
