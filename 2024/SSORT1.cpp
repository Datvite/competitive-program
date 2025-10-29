#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;
int n, m1, a[1000009], k, ans=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SSORT1.INP", "r", stdin);
    freopen("SSORT1.OUT", "w", stdout);
    cin >> n >> m1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 1; i <= m1; i++)
    {
        cin >> k;
        if (m[k] > 0)
            ans++;
    }
    cout << ans;
}
