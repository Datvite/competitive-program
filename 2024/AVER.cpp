#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("AVER.INP","r",stdin);
    freopen("AVER.OUT","w",stdout);
    int n,k;
    cin>>n>>k;
    long long a[1000068],s[1000068],x,y,dem=1,maxv=LLONG_MIN;
    s[0]=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    x=0;
    y=1;
    while (y<=n)
    {
            if ((s[y]-s[x])%k!=0)
                {
                    dem=0;
                    y=x;
                    x++;

                }
            dem++;
            y++;
            maxv=max(maxv,dem);
    }
    cout<<maxv;
}
