#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DESSEQ4.INP","r",stdin);
    freopen("DESSEQ4.OUT","w",stdout);
    long long n,a[1000068],l=0,r=0,dem=0,c[1000068],maxv=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    c[0]=1;
    a[n+1]=LLONG_MAX;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>a[i+1])
        {
            dem++;
            c[i]=c[i-1];
        }
        else
        {
            dem=0;
            c[i]=i+1;
        }
        if (dem>maxv)
        {
            l=c[i];
            r=i+1;
        }
        maxv=max(dem,maxv);
    }
    if (l==r&&l!=0&&r!=0)
        r++;
    cout<<l<<" "<<r;
}
