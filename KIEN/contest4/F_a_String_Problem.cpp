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
int t, n;
string str;
void solve()
{
    cin >> str;
    n = str.size();
    str = ' ' + str;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (str[i] != 'a')
            v.push_back(i);
    if (v.empty())
    {
        cout << n - 1 << endl;
        return;
    }
    int ans = 0;
    for (int k = 1; k <= v.size(); k++)
    {
        if (v.size() % k != 0)
            continue;
        int bl = v.size() / k;
        bool check = 1;
        for (int i = 1; i < bl; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (v[i * k + j] - v[i * k] != v[j] - v[0] || str[v[i * k + j]] != str[v[j]])
                {
                    check = 0;
                    break;
                }
            }
            if (!check)
                break;
        }
        if (check)
            {
                int tmp = v[0] - 1;
                int tmp2 = n - v.back();
                int minn = 1e18;
                for (int i = 1; i < bl; i++)
                    minn = min(minn, v[i * k] - v[i * k - 1] - 1);
                for (int i = 0; i <= tmp; i++)
                {
                    int cur = min(minn - i, tmp2);
                    if (cur >= 0)
                        ans += cur + 1;
                }
            }
    }
    cout << ans << endl;
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
