#include <bits/stdc++.h>
using namespace std;
long long n,t,s=0,a,k;
void sub1()
{
    for (int i=1;i<=n;i++)
        {
            t=i%1000000007;
            a=(t*t)%1000000007;
            k=(t*a)%1000000007;
            s=s+k;
        }
    cout<<s%1000000007;
}
void sub2()
{
    a=((n*(n+1))/2)%1000000007;
    k=(a*a)%1000000007;
    cout<<k%1000000007;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("21CS.INP","r",stdin);
    freopen("21CS.OUT","w",stdout);
    cin>>n;
    if (n<=1000000)
    {
        sub1();
    }
    else
    {
        sub2();
    }
}
