#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("MEET.INP","r",stdin);
    freopen("MEET.OUT","w",stdout);
    long double v1,v2,s,x;
    cin>>v1>>v2>>s;
    if ((2*v1)>=s)
        {
            cout<<-1;
            return 0;
        }
    s=s+v2*2;
    x=s/(v1+v2);
    cout<<fixed<<setprecision(3);
    cout<<v1*x;
}
