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
int n, a[N], dp[20][20][20][20], t;
int backtrack(int id, int minn1, int minn2, int maxn)
{
    if (id > n)
        return (minn1 + minn2 > maxn);
    if (dp[id][minn1][minn2][maxn] != -1)
        return dp[id][minn1][minn2][maxn];
    int ans = 0;
    for (int j = 1; j <= n; j++)
    {
        int minte1 = minn1;
        int minte2 = minn2;
        if (j <= minte1)
        {
            minte2 = minte1;
            minte1 = j;
        }
        else if (j < minte2)
            minte2 = j;
        ans += backtrack(id + 1, minte1, minte2, max(maxn, j));
    }
    return dp[id][minn1][minn2][maxn] = ans;
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << backtrack(1, 19, 19, 0) << endl;
    vector<int> res;
    int minn1 = 19, minn2 = 19, maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int minte1 = minn1;
            int minte2 = minn2;
            if (j <= minte1)
            {
                minte2 = minte1;
                minte1 = j;
            }
            else if (j < minte2)
                minte2 = j;
            int cur = backtrack(i + 1, minte1, minte2, max(maxn, j));
            if (t > cur)
                t -= cur;
            else
            {
                res.push_back(j);
                minn1 = minte1;
                minn2 = minte2;
                maxn = max(maxn, j);
                break;
            }
        }
    }
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    minn1 = 19, minn2 = 19, maxn = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < a[i]; j++)
        {
            int minte1 = minn1;
            int minte2 = minn2;
            if (j <= minte1)
            {
                minte2 = minte1;
                minte1 = j;
            }
            else if (j < minte2)
                minte2 = j;
            ans += backtrack(i + 1, minte1, minte2, max(maxn, j));
        }
        if (a[i] <= minn1)
        {
            minn2 = minn1;
            minn1 = a[i];
        }
        else if (a[i] < minn2)
            minn2 = a[i];
        maxn = max(maxn, a[i]);
    }
    cout << ans + 1 << endl;
}
main()
{
    skibidi;
    file("TRISEQ");
    cin >> n >> t;
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
