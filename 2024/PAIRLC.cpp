#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,maxn=LLONG_MIN,minn=LLONG_MAX,x,y,g,ans;
    cin>>n;
    if (n%2==0)
    {
        x=n/2;
        y=x;
    }
    else
    {
        x=n/2;
        y=n-x;
    }
    if (n>1000000)
       {
           n=n/1000;
       }
    for (long long i=1; i<n/2; i++)
    {
        g=__gcd(x,y);
        ans=x*y/g;
        maxn=max(maxn,ans);
        minn=min(minn,ans);
        x++;
        y--;
    }
    cout<<minn<<" "<<maxn;
}
