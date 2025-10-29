#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],gmin=LLONG_MAX,gmax=LLONG_MIN,s,k,maxv=LLONG_MIN;
void sub1()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
           {
               s=a[i]-a[j];
               s=abs(s);
               gmax=max(gmax,s);
           }
    }
    cout<<gmax;
}
void sub2()
{
    for (int i=n; i>=1; i--)
    {
        if (a[i]<gmin)
            gmin=a[i];
        else
        {
            s=gmin-a[i];
            s=abs(s);
        }
        if (a[i]>gmax)
            gmax=a[i];
        else
        {
            k=gmax-a[i];
            k=abs(k);
        }
        if (s>maxv)
            maxv=s;
        if (k>maxv)
            maxv=k;
    }
    cout<<maxv;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("21DIS.INP","r",stdin);
    freopen("21DIS.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (n<=1000)
        sub1();
    else
        sub2();
}
