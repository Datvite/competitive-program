#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DAIDIEN.INP","r",stdin);
    freopen("DAIDIEN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,h[1000068],a[1000068],t,gmax=LLONG_MIN,ld=0,lc=0;
    map<long long,long long>md;
    map<long long,long long>mc;
    md[0]=0;
    mc[0]=0;
    h[0]=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<0)
            h[i]=h[i-1]+1;
        else if (a[i]>0)
            h[i]=h[i-1]-1;
        else
            h[i]=h[i-1];
        if (md[h[i]]==0&&h[i]!=0)
            md[h[i]]=i;
        mc[h[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        t=mc[h[i]]-md[h[i]];
        if (t>gmax)
        {
            gmax=t;
            ld=md[h[i]];
            lc=mc[h[i]];
        }
        if (t==gmax&&ld>md[h[i]])
        {
            gmax=t;
            ld=md[h[i]];
            lc=mc[h[i]];
        }
    }
    if (lc==0||ld==lc)
        cout<<0;
    else
        cout<<ld+1<<" "<<lc;
    return 0;
}
