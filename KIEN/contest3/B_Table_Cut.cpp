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
int t, n, m, sum = 0;
void solve()
{
    cin >> n >> m;
    vector<vector<int>> a(n + 7, vector<int>(m + 7, 0));
    sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    int id = 0, cnt = 0, x = sum / 2, id2 = m + 1;
    for (int i = 1; i <= n; i++)
    {
        int suma = 0;
        for (int j = 1; j <= m; j++)
            suma += a[i][j];
        if (cnt + suma <= x)
        {
            cnt += suma;
            id = i;
        }
        else
            break;
    }
    int cnt1 = x - cnt;
    if (id < n && cnt1 > 0)
    {
        int suma = 0;
        for (int j = m; j >= 1; j--)
        {
            suma += a[id + 1][j];
            if (suma == cnt1)
            {
                id2 = j;
                break;
            }
        }
    }
    cout << (sum / 2) * (sum - sum / 2) << endl;
    for (int i = 1; i <= id; i++)
        cout << 'D';
    for (int j = 1; j < id2; j++)
        cout << 'R';
    if (id < n)
        cout << 'D';
    for (int j = id2; j <= m; j++)
        cout << 'R';
    for (int i = id + 2; i <= n; i++)
        cout << 'D';
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
/* I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
