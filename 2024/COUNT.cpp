#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("COUNT.INP","r",stdin);
    freopen("COUNT.OUT","w",stdout);
    long long n,x,q,a[1000068],sa[1000068],l,r;
    sa[0]=0;
    cin>>n>>x>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>0&&a[i]<x)
            sa[i]=sa[i-1]+1;
        else
            sa[i]=sa[i-1];
    }
    for (int i=1;i<=q;i++)
    {
        cin>>l>>r;
        cout<<sa[r]-sa[l-1]<<endl;;
    }
}
