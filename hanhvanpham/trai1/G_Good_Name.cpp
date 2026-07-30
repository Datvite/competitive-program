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
int n, k, a[N], ans = 0, cnt[36], res = 0;
string str;
void solve()
{
    /*for (int i = k; i <= n; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            cnt[str[j] - 'a']++;
            if (cnt[str[j] - 'a'] == 1)
                sum++;
        }
        if (sum >= k)
            ans++;
        for (int j = i + 1; j <= n; j++)
        {
            cnt[str[j - i] - 'a']--;
            if (cnt[str[j - i] - 'a'] == 0)
                sum--;
            cnt[str[j] - 'a']++;
            if (cnt[str[j] - 'a'] == 1)
                sum++;
            if (sum >= k)
                ans++;
        }
    }*/
    for (int i = 1; i <= n; i++)
        res += i;
    int l = 1, r = 1, ans = 0, sum = 0;
    while (r <= n)
    {
        cnt[str[r] - 'a']++;
        if (cnt[str[r] - 'a'] == 1)
            ans++;
        while (ans >= k)
        {
            cnt[str[l] - 'a']--;
            if (cnt[str[l] - 'a'] == 0)
                ans--;
            l++;
        }
        sum += (r - l + 1);
        r++;
    }
    cout << res - sum;
}
main()
{
    skibidi;
    file("drx02t1");
    cin >> n >> k;
    cin >> str;
    str = " " + str;
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
