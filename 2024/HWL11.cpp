#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("HWL11.INP","r",stdin);
    //freopen("HWL11.OUT","w",stdout);
    long double v1,v2,s,h,l;
    cin>>v1>>v2>>s;
    h=s/v1;
    if (v1>s||s>=v2*(h-1))
        {
            cout<<-1;
            return 0;
        }
    h=-v1/(v1-v2);
    l=v2*h;
    cout<<fixed<<setprecision(3);
    cout<<l;
}
