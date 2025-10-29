#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SCTDP.INP","r",stdin);
    freopen("SCTDP.OUT","w",stdout);
    int n;
    cin>>n;
    int t=0;
    int a[3000000],b[3000000],c[3000000];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    if (a[0]<a[1])
    {
        b[t]=0;
        t++;
    }
    for (int i=1;i<=n-1;i++)
    {
        if (a[i]<a[i-1]&&a[i]<a[i+1])
        {
            b[t]=i;
            t++;
        }
    }
    if (a[n-1]<a[n-2])
    {
        b[t]=n-1;
    }
    cout<<t<<endl;
    if (t>0)
    {
        for (int i = 0; i < t; i++)
        {
            cout << b[i]+1 << " ";
        }
        cout<<endl;
        for (int i = 0; i < t; i++)
        {
            c[i]=a[b[i]];
        }
        sort(c,c+t);
        for (int i = 0; i < t; i++)
        {
            cout<<c[i]<<" ";
        }
    }
    else
    {
        cout<<0;
    }
}
