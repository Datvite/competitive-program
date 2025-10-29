#include <bits/stdc++.h>
using namespace std;
long long a,b,ans,n,c,k,a1,a2,a3;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c;
    a=abs(a);
    b=abs(b);
    c=abs(c);
    ans=__gcd(a,b);
    k=a*b/ans;
    ans=__gcd(k,c);
    k=k*c/ans;
    cout<<k<<endl;
}
