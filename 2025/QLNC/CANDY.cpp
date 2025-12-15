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
int n, k, a[N], ans = 1e18, cnt = 0;
vector<int> v, res;
void backtrack(int id, int last, int sum, int maxx, int minn)
{
    if (sum > k)
        return;
    if (id > n)
    {
        if (sum == k)
        {
            cnt++;
            if (maxx - minn < ans)
            {
                ans = maxx - minn;
                res = v;
            }
        }
        return;
    }
    for (int i = last; i >= 1; i--)
    {
        v.push_back(i);
        backtrack(id + 1, i, sum + i, max(maxx, i), min(minn, i));
        v.pop_back();
    }
}
main()
{
    skibidi;
    file("CANDY");
    cin >> n >> k;
    backtrack(1, k, 0, 0, 1e18);
    cout << cnt << endl;
    for (auto x : res)
        cout << x << " ";
}
