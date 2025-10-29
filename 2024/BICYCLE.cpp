#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("BICYCLE.INP","r",stdin);
    //freopen("BICYCLE.OUT","w",stdout);
    long long n,a[3000009],t=0,maxv=0;
    cin>>n;
    for (int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    sort (a+1,a+2*n+1);
    for (int i=1;i<=n;i++)
    {
        t=a[i]+a[2*n-i+1];
        maxv=max(maxv,t);
        cout<<t;
    }
    cout<<maxv;
}
