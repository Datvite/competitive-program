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
ll n, a[N], sum = 0, m;
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    sum = a[1];
    if (sum > m)
    {
        cout << 0 << endl;
        return;
    }
    if (sum == m)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (sum < a[i] - 1)
        {
            cout << 0 << endl;
            return;
        }
        sum += a[i];
        if (sum >= m)
        {
            cout << i << endl;
            return;
        }
    }
}
main()
{
    skibidi;
    file("SELECT");
    cin >> n >> m;
    sol();
}
