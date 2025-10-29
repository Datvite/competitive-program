#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("19TRI.INP","r",stdin);
    freopen("19TRI.OUT","w",stdout);
    cin>>a>>b>>c;
    if (a*a+b*b==c*c||b*b+c*c==a*a||c*c+a*a==b*b)
        cout<<0;
    else if (a*a>b*b+c*c||b*b>c*c+a*a||c*c>a*a+b*b)
       {
           cout<<2;
       }
    else
        cout<<1;
}
