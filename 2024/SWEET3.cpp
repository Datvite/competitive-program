#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SWEET3.INP","r",stdin);
    freopen("SWEET3.OUT","w",stdout);
    long long n,m,a[1000068],s[1000068],dem=0,t;
    cin>>n>>m;
    s[0]=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int y=0;y<i;y++)
        {
            t=s[i]-s[y];
            if (t%m==0)
                dem++;
        }
    }
    cout<<dem;
}
