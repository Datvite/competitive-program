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
const int N = 1e3 + 69;
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
int n, k, a[N], f[N][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= a[i]; j--)
        {
            int cur = j - a[i];
            for (int v = j; v >= a[i]; v--)
            {
                int cur2 = v - a[i];
                if (!f[cur][cur2])
                    continue;
                f[j][v] = 1;
                f[j][cur2] = 1;
            }
        }
    }
    vector<int> vec;
    for (int i = 0; i <= k; i++)
        if (f[k][i])
            vec.push_back(i);
    cout << vec.size() << endl;
    for (int x : vec)
        cout << x << " ";
}
main()
{
    skibidi;
    file("");
    cin >> n >> k;
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
