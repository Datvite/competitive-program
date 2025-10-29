#include<bits/stdc++.h>
//#include<fstream>
using namespace std;
int main()
{
    freopen("FRACSUM.INP","r",stdin);
    freopen("FRACSUM.OUT","w",stdout);
    long long a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    x=a*d+b*c;
    y=b*d;
    long long t=__gcd(x,y);
    cout<<x/t<<" "<<y/t;
}
