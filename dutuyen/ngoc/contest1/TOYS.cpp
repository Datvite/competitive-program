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
int n, a[N], cnt[100], ansl, ansr, dif1 = 1e9, len1 = 1;
string str;
void solve()
{
    for (int mid = 1; mid <= 26; mid++)
    {
        for (int i = 1; i <= 67; i++)
            cnt[i] = 0;
        int dif = 0, l = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cnt[str[i] - 'a' + 1] == 0)
                dif++;
            cnt[str[i] - 'a' + 1]++;
            while (dif > mid)
            {
                cnt[str[l] - 'a' + 1]--;
                if (cnt[str[l] - 'a' + 1] == 0)
                    dif--;
                l++;
            }
            if (dif * len1 < (i - l + 1) * dif1)
            {
                ansl = l;
                ansr = i;
                dif1 = dif;
                len1 = i - l + 1;
            }
            else if (dif * len1 == (i - l + 1) * dif1)
            {
                if (l + 1 < ansl)
                {
                    ansl = l;
                    ansr = i;
                }
            }
        }
    }
    cout << ansl << " " << ansr;
}
main()
{
    skibidi;
    file("TOYS");
    cin >> n;
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
