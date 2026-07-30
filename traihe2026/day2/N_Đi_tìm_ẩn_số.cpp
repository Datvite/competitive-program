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
struct node
{
    string name;
    int value, correct;
};
int n, q, a[N], cnt[N], c[N], sum = 0, ans[N];
vector<int> w[N];
string s[N];
vector<node> v;
bool cmp(node a, node b)
{
    if (a.value != b.value)
        return a.value > b.value;
    if (a.correct != b.correct)
        return a.correct > b.correct;
    return a.name < b.name;
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);
        int p = line.size() - 1;
        vector<int> tmp;
        while (true)
        {
            int r = p;
            while (p >= 0 && isdigit(line[p]))
                p--;
            tmp.push_back(stoi(line.substr(p + 1, r - p)));
            while (p >= 0 && line[p] == ' ')
                p--;
            if (p < 0 || !isdigit(line[p]))
                break;
        }
        reverse(tmp.begin(), tmp.end());
        c[i] = tmp[0];
        w[i].resize(c[i] + 1);

        for (int j = 1; j <= c[i]; j++)
        {
            w[i][j] = tmp[j];
            cnt[w[i][j]]++;
        }
        s[i] = line.substr(0, p + 1);
    }
    for (int i = 1; i <= q; i++)
        sum += cnt[i];
    v.resize(n);
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= c[i]; j++)
            res += cnt[w[i][j]];
        v[i - 1].name = s[i];
        v[i - 1].value = sum - res;
        v[i - 1].correct = q - c[i];
        // cout << s[i] << " " << sum - res << endl;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].name << " " << v[i].value << endl;
    }
}
main()
{
    skibidi;
    file("dtas");
    cin >> n >> q;
    cin.ignore();
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
