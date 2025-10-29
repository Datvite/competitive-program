#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("FEEDING.INP","r",stdin);
    freopen("FEEDING.OUT","w",stdout);
    long long n,ans=0;
    cin>>n;
    long long a[1000009],b[1000009],c[1000009];
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    c[0]=LLONG_MAX;
    for (int i=1;i<=n;i++)
        {
            cin>>b[i];
            if (b[i]<c[i-1])
                c[i]=b[i];
            else
                c[i]=c[i-1];
        }
    for (int i=1;i<=n;i++)
        {
            ans=ans+a[i]*c[i];
        }
    cout<<ans;
}
