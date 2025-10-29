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
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, a[N], Dodd[N], Deven[N], maxn = 0, L = 1, R = 0;
string str;
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        if (i > R)
            Dodd[i] = 0;
        else
            Dodd[i] = min(R - i, Dodd[L + R - i]);
        while (i - Dodd[i] - 1 >= 1 && i + Dodd[i] + 1 <= n && str[i - Dodd[i] - 1] == str[i + Dodd[i] + 1])
            Dodd[i]++;
        if (Dodd[i] * 2 + 1 > maxn)
            maxn = Dodd[i] * 2 + 1;
        if (i + Dodd[i] > R)
        {
            L = i - Dodd[i];
            R = i + Dodd[i];
        }
    }
    L = 1, R = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i + 1;
        if (i > R)
            Deven[i] = 0;
        else
            Deven[i] = min(R - i, Deven[L + R - j]);
        while (i - Deven[i] >= 1 && j + Deven[i] <= n && str[i - Deven[i]] == str[j + Deven[i]])
            Deven[i]++;
        if (Deven[i] * 2 > maxn)
            maxn = Deven[i] * 2;
        if (j + Deven[i] > R)
        {
            L = j - Deven[i];
            R = i + Deven[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (Dodd[i] * 2 + 1 == maxn)
        {
            cout << str.substr(i - Dodd[i], maxn) << endl;
            return;
        }
        if (Deven[i] * 2 == maxn)
        {
            cout << str.substr(i - Deven[i] + 1, maxn) << endl;
            return;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> str;
    n = str.size();
    str = " " + str;
    sol();
}
