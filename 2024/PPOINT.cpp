#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PPOINT.INP","r",stdin);
    freopen("PPOINT.OUT","w",stdout);
    long long n,v,a[1000068],t=0,l=0,d,dodai,minv=LLONG_MAX;
    map<long long,long long>m;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>v;
        m[a[i]]=v;
    }
    for (int i=1; i<=n; i++)
    {
        t=m[a[i]];
        l=0;
        for (int j=i; j<=n; j++)
        {
            if (m[a[j]]!=t&&l==0)
            {
                l=m[a[j]];
            }
            if (m[a[j]]!=t&&m[a[j]]!=l)
            {
                dodai=a[j]-a[i];
                minv=min(minv,dodai);
            }
        }
    }
    if (minv>=10000000000||minv<0)
        cout<<-1;
    else
        cout<<minv;
}
