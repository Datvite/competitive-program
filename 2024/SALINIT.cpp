#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,k,g;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    x=abs(k-n);
    y=abs(m-k);
    if (n<k&&m<k||n>k&&m>k)
    {
        cout<<0;
        return 0;
    }
    if (n==k||m==k)
    {
        cout<<1;
        return 0;
    }
    g=__gcd(x,y);
    x=x/g;
    y=y/g;
    cout<<x+y;
}
