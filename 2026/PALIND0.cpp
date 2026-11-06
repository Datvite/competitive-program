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
int n, a[N];
struct Manacher {
    int n;
    string s;
    vector<int> Dodd, Deven;
    int max_len;
    Manacher(const string &str) {
        s = " " + str;
        n = str.size();
        Dodd.assign(n + 2, 0);
        Deven.assign(n + 2, 0);
        max_len = 0;
        build();
    }
    void build() {
        int L = 1, R = 0;
        for (int i = 1; i <= n; i++) {
            if (i > R)
                Dodd[i] = 0;
            else
                Dodd[i] = min((int)(R - i), Dodd[L + R - i]);
            while (i - Dodd[i] - 1 >= 1 && i + Dodd[i] + 1 <= n && s[i - Dodd[i] - 1] == s[i + Dodd[i] + 1])
                Dodd[i]++;
            if (Dodd[i] * 2 + 1 > max_len)
                max_len = Dodd[i] * 2 + 1;
            if (i + Dodd[i] > R) {
                L = i - Dodd[i];
                R = i + Dodd[i];
            }
        }
        L = 1, R = 0;
        for (int i = 1; i < n; i++) {
            int j = i + 1;
            if (i > R)
                Deven[i] = 0;
            else
                Deven[i] = min((int)(R - i), Deven[L + R - j]);
            while (i - Deven[i] >= 1 && j + Deven[i] <= n && s[i - Deven[i]] == s[j + Deven[i]])
                Deven[i]++;
            if (Deven[i] * 2 > max_len)
                max_len = Deven[i] * 2;
            if (j + Deven[i] > R) {
                L = j - Deven[i];
                R = i + Deven[i];
            }
        }
    }
    string getLongestPalindrome() {
        for (int i = 1; i <= n; i++) {
            if (Dodd[i] * 2 + 1 == max_len) {
                return s.substr(i - Dodd[i], max_len);
            }
            if (Deven[i] * 2 == max_len) {
                return s.substr(i - Deven[i] + 1, max_len);
            }
        }
        return "";
    }
    bool isPalindrome(int l, int r) {
        int len = r - l + 1;
        if (len % 2 == 1) {
            int mid = (l + r) / 2;
            return (Dodd[mid] * 2 + 1 >= len);
        } else {
            int mid1 = (l + r) / 2;
            int mid2 = mid1 + 1;
            return (Deven[mid1] * 2 >= len);
        }
    }
};
string str;
void solve()
{
    Manacher manas(str);
    cout << manas.getLongestPalindrome().size() ;
}
main()
{
    skibidi;
    file("PALIND0");
    cin >> str;
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
