#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SPSUM5.INP","r",stdin);
    freopen("SPSUM5.OUT","w",stdout);
    int n;
    cin>>n;
    int a[1000068],s[1000068],smin[1000068],y=0,x=0,l=0,r=0;
    smin[0]=0;
    s[0]=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if (s[i]<smin[i-1])
            smin[i]=s[i];
        else
            smin[i]=smin[i-1];
    }
    x=n;
    y=n;
    while (y>0)
    {
        while (s[x]-smin[y-1]<0)
            {
                x--;
            }
        if (s[x]-smin[y-1]>0&&x-y>r-l)
        {
            l=y;
            r=x;
        }
        y--;
    }
    cout<<l<<" "<<r;
}
