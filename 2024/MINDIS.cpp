#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("MINDIS.INP","r",stdin);
    freopen("MINDIS.OUT","w",stdout);
    int n,m,s;
    cin>>n>>m;
    long long a[1000068];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    a[0] = a[1];
    a[n + 1] = LLONG_MAX;
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
    {
        cin>>s;
        auto k = lower_bound(a + 1, a + n + 1, s) - a;
        if (abs(a[k]-s)<=abs(a[k-1]-s))
            cout<<abs(a[k]-s)<<'\n';
        else
            cout<<abs(a[k-1]-s)<<'\n';
    }
}
