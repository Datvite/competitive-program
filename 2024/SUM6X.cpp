#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("SUM6X.INP","r",stdin);
    //freopen("SUM6X.OUT","w",stdout);
    long double n,x,s=0,l=0,q=1;
    cin>>n>>x;
    for (int i=1;i<=n;i++)
        {
            l=l+i;
            q=q*x;
            s=s+q/l;
        }
    cout<<fixed<<setprecision(6);
    cout<<s;
}
