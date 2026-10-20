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
int n, nn, k, a[N], sum[N], cnt = 1;
bool check[N], ins = 1;
string str;
struct KMP
{
    vector<int> pi;
    void build(const string &s)
    {
        int n = s.size() - 1;
        pi.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            int j = pi[i - 1];
            while (j >= 1 && s[j + 1] != s[i])
                j = pi[j];
            if (s[j + 1] == s[i])
                pi[i] = j + 1;
            else
                pi[i] = 0;
        }
    }
};
void solve()
{
    cin >> str;
    n = str.size();
    str = " " + str;
    KMP kmp;
    kmp.build(str);
    int len = n;
    while (len > 0)
    {
        check[len] = 1;
        len = kmp.pi[len];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        sum[a[i]]++;
        sum[a[i] + n]--;
    }
    for (int i = 2; i <= k; i++)
    {
        int tmp = n - (a[i] - a[i - 1]);
        if (tmp > 0 && !check[tmp])
        {
            ins = 0;
            break;
        }
    }
    for (int i = 1; i <= nn; i++)
    {
        sum[i] += sum[i - 1];
        //cout << i << " " << sum[i] << endl;
        if (sum[i] == 0)
            cnt = mul(cnt, 26);
    }
    if (ins)
        cout << cnt << endl;
    else
        cout << 0 << endl;
}
main()
{
    skibidi;
    file("");
    cin >> nn >> k;
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
