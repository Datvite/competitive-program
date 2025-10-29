#include <bits/stdc++.h>
using namespace std;
#define int long long
#define task "ANTMOVES"
#define fi first
#define se second
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m, l;
    cin >> n >> l >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, w, d;
        cin >> x >> w >> d;
        int t;
        if (d == 0)
        {
            t = x;
        }
        else
        {
            t = l - x;
        }
        a[i] = {t, w};
    }
    sort(a.begin(), a.end());
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i - 1].se;
    }
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        q[i] = {t, i};
    }
    vector<int> ans(m);
    sort(q.begin(), q.end());
    for (int i = 0; i < m; i++)
    {
        int t = q[i].fi;
        int id = q[i].se;
        int k = upper_bound(a.begin(), a.end(), pair<int, int>{t, LLONG_MAX}) - a.begin();
        ans[id] = s[k];
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}