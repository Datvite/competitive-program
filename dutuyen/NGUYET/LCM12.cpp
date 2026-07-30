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
int n;
int ans[N];
int prime[N];
bool check[N];
void build()
{
    for (int i = 2; i < N; i++)
    {
        if (!prime[i])
        {
            check[i] = 1;
            if (i * i < N)
                check[i * i] = 1;
            for (int j = i; j < N; j += i)
            {
                prime[j] = i;
            }
        }
        else
        {
            if (check[i])
            {
                if (i * prime[i] < N)
                    check[i * prime[i]] = 1;
            }
        }
    }
    ans[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (check[i])
            ans[i] = (ans[i - 1] * prime[i]) % 1000000000;
        else
            ans[i] = ans[i - 1];

        while (ans[i] > 0 && ans[i] % 10 == 0)
            ans[i] /= 10;
    }
}
void solve()
{
    cout << ans[n] % 10 << endl;
}
main()
{
    skibidi;
    file("lcm12");
    build();
    while (cin >> n && n != 0)
    {
        solve();
    }
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
