#include <bits/stdc++.h>
using namespace std;
struct pta
{
    int dau;
    int cuoi;
    int vt;
    bool chon = false;
};
pta a[3000009];
bool cmp(pta x, pta y)
{
    if (x.cuoi < y.cuoi)
        return true;
    return false;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ACT21.INP", "r", stdin);
    freopen("ACT21.OUT", "w", stdout);
    int n, t, g, gmax = 0, x = 1;
    cin >> n;
    int b[300009];
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> g;
        a[i].dau = t;
        a[i].cuoi = g;
        a[i].vt = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int r = a[1].cuoi;
    a[1].chon = true;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].dau >= r)
        {
            x++;
            a[i].chon = true;
            r = a[i].cuoi;
        }
        gmax = max(gmax, x);
    }
    cout << gmax << endl;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].chon)
            cout << a[i].vt << endl;
    }
}
