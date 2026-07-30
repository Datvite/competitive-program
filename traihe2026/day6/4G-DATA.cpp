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
char ask(vector<int> a, vector<int> b)
{
    if (a.empty() || b.empty())
        return '=';
    cout << "COMPARE " << a.size();
    for (auto x : a)
        cout << " " << x;
    cout << " " << b.size();
    for (auto x : b)
        cout << " " << x;
    cout << endl;
    char res;
    cin >> res;
    return res;
}
int check(vector<int> t, vector<int> b, int ty, int avoid = -1)
{
    while (t.size() > 1)
    {
        int mid = t.size() / 2;
        vector<int> left, right;
        for (int x : t)
        {
            if (x == avoid)
                continue;
            if (left.size() < mid)
                left.push_back(x);
            else
                right.push_back(x);
        }
        if (left.empty())
            return right[0];
        if (right.empty())
            return left[0];
        vector<int> tmp(b.begin(), b.begin() + left.size());
        char res = ask(left, tmp);

        if (ty == 10)
        {
            if (res == '<')
                t = left;
            else
                t = right;
        }
        else
        {
            if (res == '>')
                t = left;
            else
                t = right;
        }
    }
    return t[0];
}
void solve()
{
    vector<int> a(128);
    for (int i = 0; i < 128; i++)
        a[i] = i + 1;
    vector<int> A(a.begin(), a.begin() + 64);
    vector<int> B(a.begin() + 64, a.end());
    char res = ask(A, B);
    int ans1, ans2;
    if (res == '<')
    {
        ans1 = check(A, B, 10);
        ans2 = check(B, A, 30);
    }
    else if (res == '>')
    {
        ans1 = check(B, A, 10);
        ans2 = check(A, B, 30);
    }
    else
    {
        vector<int> A1(A.begin(), A.begin() + 32);
        vector<int> A2(A.begin() + 32, A.end());
        char res2 = ask(A1, A2);
        vector<int> t;
        vector<int> v;
        if (res2 != '=')
        {
            t = A;
            v = B;
        }
        else
        {
            vector<int> B1(B.begin(), B.begin() + 32);
            char res3 = ask(A1, B1);
            if (res3 != '=')
            {
                t = A;
                v = B;
            }
            else
            {
                t = B;
                v = A;
            }
        }
        ans1 = check(t, v, 10);
        ans2 = check(t, v, 30, ans1);
    }
    cout << "ANSWER " << ans1 << " " << ans2 << endl;
}
main()
{
    skibidi;
    file("");
    cin >> n;
    while (n--)
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
