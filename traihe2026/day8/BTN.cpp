#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
const int MOD = 998244353;
string str;
int n, open[N], close[N], pre[N], suf[N], fact[N], invfact[N], sufc[N], ans = 0, sumn[N], sums[N], cnt = 0;
int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void cal()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[N - 1] = binpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}
int nCk(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
void sub1()
{
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == ')')
            continue;
        sufc[suf[i + 1] + 1] = 0;
        for (int j = suf[i + 1]; j >= 0; j--)
            sufc[j] = (sufc[j + 1] + nCk(suf[i + 1], j)) % MOD;
        for (int j = 0; j <= pre[i - 1]; j++)
        {
            int needc = open[i - 1] + j + 1 - close[i + 1];
            int minc = max(0LL, needc);
            if (minc <= suf[i + 1])
            {
                int l = nCk(pre[i - 1], j);
                int r = sufc[minc];
                int cur = (l * r) % MOD;
                ans = (ans + cur) % MOD;
            }
        }
    }
    cout << ans;
}
void sub2()
{
    if (cnt >= 0)
    {
        sumn[0] = nCk(cnt, 0);
        for (int j = 1; j <= cnt; j++)
            sumn[j] = (sumn[j - 1] + nCk(cnt, j)) % MOD;
    }
    if (cnt >= 1)
    {
        sums[0] = nCk(cnt - 1, 0);
        for (int j = 1; j <= cnt; j++)
            sums[j] = (sums[j - 1] + nCk(cnt - 1, j)) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        // suf[i + 1] - open[i - 1] - 1 + close[i + 1] >= z + x
        if (str[i] == ')')
            continue;
        int d = open[i - 1] + 1 - close[i + 1];
        int cur1 = suf[i + 1] - d;
        int cur2 = 0;
        if (str[i] == '(')
            cur2 = cnt;
        else
            cur2 = cnt - 1;
        int lim = min(cur1, cur2);
        if (lim < 0)
            continue;
        if (str[i] == '(')
            ans += sumn[lim];
        else
            ans += sums[lim];
        ans %= MOD;
    }
    cout << ans;
}
vector<int> pos;
int get(string s)
{
    int cnt = 0, l = 0, r = s.size() - 1;
    while(l < r)
    {
        while(l < r && s[l] != '(')
            l++;
        while(l < r && s[r] != ')')
            r--;
        if (l < r)
        {
            cnt++;
            l++;
            r--;
        }
    }
    return cnt;
}
void backtrack(int idx)
{
    if (idx == pos.size())
    {
        ans = (ans + get(str)) % MOD;
        return;
    }
    int id = pos[idx];
    str[id] = '(';
    backtrack(idx + 1);
    str[id] = ')';
    backtrack(idx + 1);
}
void sub3()
{
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == '?')
            pos.push_back(i);
    }
    backtrack(0);
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;
    n = str.size();
    str = ' ' + str;
    cal();
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == '(')
            open[i] = open[i - 1] + 1;
        else
            open[i] = open[i - 1];
        if (str[i] == '?')
        {
            pre[i] = pre[i - 1] + 1;
            cnt++;
        }
        else
            pre[i] = pre[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (str[i] == ')')
            close[i] = close[i + 1] + 1;
        else
            close[i] = close[i + 1];
        if (str[i] == '?')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    }
    if (n <= 20)
        sub3();
    else if (n <= 1000)
        sub1();
    else
        sub2();
}