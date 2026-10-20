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
const int N = 1e7 + 69;
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
int n, q, a[N], prime[N];
void sieve()
{
    for (int i = 2; i < N; i++)
        prime[i] = i;
    for (int i = 2; i * i < N; i++)
        if (prime[i] == i)
        {
            prime[i] = i;
            for (int j = i * i; j < N; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            a[i] = 1;
        else
            a[i] = (prime[a[i]] + 1) * (prime[a[i]] + 1);
    while (q--)
    {
        int x;
        cin >> x;
        deque<int> dqmin, dqmax;
        int l = 1, ans = 0;
        for (int r = 1; r <= n; r++)
        {
            while (!dqmin.empty() && a[dqmin.back()] >= a[r])
                dqmin.pop_back();
            while (!dqmax.empty() && a[dqmax.back()] <= a[r])
                dqmax.pop_back();
            dqmin.push_back(r);
            dqmax.push_back(r);
            while (!dqmin.empty() && !dqmax.empty() && l <= r && a[dqmax.front()] - a[dqmin.front()] > x)
            {
                if (dqmin.front() == l)
                    dqmin.pop_front();
                if (dqmax.front() == l)
                    dqmax.pop_front();
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> q;
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
