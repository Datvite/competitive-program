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
int n, a[N], ans = -1e18;
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= 6; i++)
    {
        vector<int> vals;
        for (int j = 1; j <= i; j++)
            vals.push_back(a[j]);
        for (int j = n - (6 - i) + 1; j <= n; j++)
            vals.push_back(a[j]);
        for (int id1 = 0; id1 < 6; id1++)
        {
            for (int id2 = id1 + 1; id2 < 6; id2++)
            {
                for (int id3 = id2 + 1; id3 < 6; id3++)
                {
                    int sum1 = vals[id1] * vals[id2] * vals[id3];
                    int sum2 = 1;
                    for (int id4 = 0; id4 < 6; id4++)
                    {
                        if (id4 != id1 && id4 != id2 && id4 != id3)
                            sum2 *= vals[id4];
                    }
                    ans = max(ans, sum1 + sum2);
                }
            }
        }
    }
    cout << ans;
}
main()
{
    skibidi;
    file("NUM6");
    cin >> n;
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
