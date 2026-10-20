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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 2e7 + 69;
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
int n, prime[N];
void sieve()
{
    for (int i = 2; i < N; i++)
        prime[i] = i;
    for (int i = 2; i * i < N; i++)
        if (prime[i] == i)
            for (int j = i * i; j < N; j += i)
                prime[j] = i;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int x, y, ans = 1;
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int g = gcd(x, y);
        x /= g;
        y /= g;
        if (x % 2 != y % 2)
        {
            while (g % 2 == 0)
                g /= 2;
            for (int p = 3; p * p <= g && g >= N; p += 2)
            {
                if (g % p == 0)
                {
                    int cnt = 0;
                    while (g % p == 0)
                    {
                        g /= p;
                        cnt++;
                    }
                    ans *= (cnt + 1);
                }
            }
            if (g < N)
                while (g > 1)
                {
                    int p = prime[g], cnt = 0;
                    while (g % p == 0)
                    {
                        g /= p;
                        cnt++;
                    }
                    ans *= (cnt + 1);
                }
            else if (g > 1)
            {
                ans *= 2;
            }
        }
        else
            ans = 0;
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("TGACH");
    cin >> n;
    sieve();
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
