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
struct BigInt
{
    static const int base = 1000000000;
    static const int base_digits = 9;
    vector<int> a;
    int sign;

    BigInt() : sign(1) {}
    BigInt(long long v) { *this = v; }
    BigInt(const string &s) { read(s); }

    void operator=(long long v)
    {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        while (v > 0)
        {
            a.push_back(v % base);
            v /= base;
        }
    }

    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            pos++;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits)
        {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + (s[j] - '0');
            a.push_back(x);
        }
        trim();
    }

    void trim()
    {
        while (!a.empty() && a.back() == 0)
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const { return a.empty(); }

    friend ostream &operator<<(ostream &out, const BigInt &v)
    {
        if (v.sign == -1 && !v.isZero())
            out << '-';
        if (v.a.empty())
            out << 0;
        else
        {
            out << v.a.back();
            for (int i = (int)v.a.size() - 2; i >= 0; i--)
                out << setw(base_digits) << setfill('0') << v.a[i];
        }
        return out;
    }

    friend istream &operator>>(istream &in, BigInt &v)
    {
        string s;
        in >> s;
        v.read(s);
        return in;
    }

    static int absCmp(const BigInt &a, const BigInt &b)
    {
        if (a.a.size() != b.a.size())
            return a.a.size() < b.a.size() ? -1 : 1;
        for (int i = (int)a.a.size() - 1; i >= 0; i--)
            if (a.a[i] != b.a[i])
                return a.a[i] < b.a[i] ? -1 : 1;
        return 0;
    }

    bool operator<(const BigInt &v) const
    {
        if (sign != v.sign)
            return sign < v.sign;
        int cmp = absCmp(*this, v);
        return sign == 1 ? (cmp < 0) : (cmp > 0);
    }
    bool operator>(const BigInt &v) const { return v < *this; }
    bool operator<=(const BigInt &v) const { return !(v < *this); }
    bool operator>=(const BigInt &v) const { return !(*this < v); }
    bool operator==(const BigInt &v) const { return sign == v.sign && a == v.a; }
    bool operator!=(const BigInt &v) const { return !(*this == v); }

    BigInt operator-() const
    {
        BigInt res = *this;
        if (!res.isZero())
            res.sign = -sign;
        return res;
    }

    BigInt operator+(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            BigInt res = v;
            int carry = 0;
            for (size_t i = 0; i < max(a.size(), v.a.size()) || carry; i++)
            {
                if (i == res.a.size())
                    res.a.push_back(0);
                long long sum = res.a[i] + carry + (i < a.size() ? a[i] : 0LL);
                carry = sum >= base;
                if (carry)
                    sum -= base;
                res.a[i] = (int)sum;
            }
            return res;
        }
        return *this - (-v);
    }

    BigInt operator-(const BigInt &v) const
    {
        if (sign == v.sign)
        {
            if (absCmp(*this, v) >= 0)
            {
                BigInt res = *this;
                int carry = 0;
                for (size_t i = 0; i < v.a.size() || carry; i++)
                {
                    long long sub = res.a[i] - (i < v.a.size() ? v.a[i] : 0) - carry;
                    carry = sub < 0;
                    if (carry)
                        sub += base;
                    res.a[i] = (int)sub;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    BigInt operator*(const BigInt &v) const
    {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.assign(a.size() + v.a.size(), 0);
        for (size_t i = 0; i < a.size(); i++)
        {
            long long carry = 0;
            for (size_t j = 0; j < v.a.size() || carry; j++)
            {
                long long cur = res.a[i + j] + (long long)a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
                res.a[i + j] = (int)(cur % base);
                carry = cur / base;
            }
        }
        res.trim();
        return res;
    }

    BigInt operator/(int v) const
    {
        BigInt res = *this;
        res.sign *= (v < 0 ? -1 : 1);
        v = abs(v);
        long long rem = 0;
        for (int i = (int)res.a.size() - 1; i >= 0; i--)
        {
            long long cur = res.a[i] + rem * base;
            res.a[i] = (int)(cur / v);
            rem = cur % v;
        }
        res.trim();
        return res;
    }

    int operator%(int v) const
    {
        long long m = 0;
        for (int i = (int)a.size() - 1; i >= 0; i--)
            m = (a[i] + m * base) % v;
        return (int)(m * sign);
    }
};
int n, k;
BigInt dp[201][201];
bool vis[201][201];
string str;
BigInt backtrack(int id, int depth, int lk)
{
    if (depth > lk || depth < 0)
        return 0;
    if (id == str.length())
        return (depth == 0);
    if (vis[id][depth])
        return dp[id][depth];
    vis[id][depth] = 1;
    BigInt ans = 0;
    if (str[id] == '(')
        ans = ans + backtrack(id + 1, depth + 1, lk);
    if (str[id] == ')')
        ans = ans + backtrack(id + 1, depth - 1, lk);
    if (str[id] == '?')
        ans = ans + backtrack(id + 1, depth + 1, lk) + backtrack(id + 1, depth - 1, lk);
    return dp[id][depth] =ans;
}
BigInt calc(int lk)
{
    memset(vis, 0, sizeof(vis));
    return backtrack(0, 0, lk);
}
void solve()
{
    cout << calc(k) - calc(k - 1) << endl;
}
main()
{
    skibidi;
    file("RESTORE2");
    cin >> k >> str;
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
