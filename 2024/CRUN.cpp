#include <bits/stdc++.h>
using namespace std;
long long z,n,a,x,b,y,k,d,e,k1;
long long kc(long long a,long long b)
{
    return (b-a+n)%n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>a>>b;
    if (kc(a,b)>kc(b,a))
        cout<<kc(b,a);
    else
        cout<<kc(a,b);
}
