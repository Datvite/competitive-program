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
const int Q = 120005;
short seqs[Q][12];
int mexv[Q];
int sz = 0;
int cur[26];
int freq[205];
int n, m, mod, ans[26];
int mex()
{
    for (int i = 0; i <= m + 1; ++i)
    {
        if (freq[i] == 0)
            return i;
    }
    return m + 1;
}
void ql(int pos)
{
    if (pos == n)
    {
        mexv[sz] = mex();
        for (int i = 0; i < n; ++i)
        {
            seqs[sz][i] = cur[i];
        }
        sz++;
        return;
    }
    for (int i = 0; i <= m; ++i)
    {
        cur[pos] = i;
        if (i <= m + 1)
            freq[i]++;
        ql(pos + 1);
        if (i <= m + 1)
            freq[i]--;
    }
}

void solve()
{
    sz = 0;
    memset(freq, 0, sizeof(freq));
    ql(0);

    for (int i = 0; i < sz; ++i)
    {
        for (int j = i + 1; j < sz; ++j)
        {
            int k = 1;
            while (k <= n && seqs[i][k - 1] == seqs[j][k - 1])
                k++;

            if (k <= n && seqs[i][k - 1] < seqs[j][k - 1])
            {
                if (mexv[i] > mexv[j])
                {
                    ans[k] = (ans[k] + 1) % mod;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
}
main()
{
    skibidi;
    file("CMEX");
    cin >> n >> m >> mod;
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
