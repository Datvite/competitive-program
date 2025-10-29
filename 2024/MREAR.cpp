#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MREAR.INP","r",stdin);
    freopen("MREAR.OUT","w",stdout);
    long long xa[1000000],ya[1000000],xb[1000000],yb[1000000],dientich,minv=LLONG_MAX,s;
    for (int i=1;i<=3;i++)
    {
        cin>>xa[i]>>ya[i]>>xb[i]>>yb[i];
    }
    for (int i=1;i<=3;i++)
    {
            s=abs(xa[i]-xb[i])*abs(ya[i]-yb[i]);
            minv=min(minv,s);
    }
    cout<<minv;
}
