#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
using namespace std;

int main()
{
    file("DANPAIRS")
    int n, m,k;
    cin >> n >> m>>k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a.begin(), a.end());
    set<int>c;
    ll maxn = 0;
    for (ll p : b)
    {
        auto id = lower_bound(a.begin(), a.end(), p) - a.begin();
        ll t =LLONG_MAX;
        if (id < n&&id > 0)
        {
            if (abs(a[id - 1] - p)<abs(a[id] - p))
            {
                t=abs(a[id - 1] - p);
                c.insert(t);
                a.erase(a.begin()+id-1);
            }
            else
            {
                t=abs(a[id] - p);
                c.insert(t);
                a.erase(a.begin()+id);
            }
        }
        else if (id < n)
        {
            t=abs(a[id] - p);
            c.insert(t);
            a.erase(a.begin()+id);
        }
        else if (id >0)
        {
            t=abs(a[id] - p);
            c.insert(t);
            a.erase(a.begin()+id);
        }
    }
    for (auto i: c)
    {
        maxn=max(maxn,(ll)i);
        k--;
        if (k==0)
            break;
    }
    cout << maxn << endl;
    return 0;
}
