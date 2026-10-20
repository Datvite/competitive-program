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
#define int unsigned long long
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
int t, l, r;
int power(int x, int k, int lim)
{
    int res = 1;
    for (int i = 0; i < k; ++i)
    {
        if (x != 0 && res > lim / x)
            return lim + 1;
        res *= x;
    }
    return res;
}
int check(int r, int k)
{
    int low = 1, high = r, ans = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (power(mid, k, r) <= r)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
void solve()
{
    cin >> l >> r;
    for (int k = 64; k >= 1; --k)
    {
        int x = check(r, k);
        if (x >= 2)
        {
            int val = power(x, k, r);
            if (val >= l && val <= r)
            {
                cout << k << endl;
                return;
            }
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
