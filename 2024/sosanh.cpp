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
    cin>>z;
    for (int i=1; i<=z; i++)
    {
        cin>>n>>a>>x>>b>>y;
        k=kc(a,b);
        k1=k+n;
        d=kc(a,x);
        e=kc(y,b);
        if (k%2==0&&d>=k/2&&e>=k/2||k1%2==0&&d>=k1/2&&e>=k1/2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }
}
