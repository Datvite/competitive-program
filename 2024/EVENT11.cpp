#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("EVENT11.INP","r",stdin);
    freopen("EVENT11.OUT","w",stdout);
    long long n,maxv=0,t,dem=0,a[1000068];
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++)
    {
        dem=0;
        for (int j=i; j<=n; j++)
        {
            if (a[j]>0&&a[j]%2==0)
            {
                dem++;
            }
            else
                dem=0;
            if (dem>maxv)
            {
                t=i;
                maxv=dem;
            }
        }
    }
    if (maxv!=0)
    {
        cout<<maxv<<endl;
        cout<<t;
    }
    else
        cout<<0;
}
