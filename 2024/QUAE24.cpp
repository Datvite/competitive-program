#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("QUAE24.INP","r",stdin);
    freopen("QUAE24.OUT","w",stdout);
    long double a,b,c,d,x1,x2;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    cout<<fixed<<setprecision(4);
    if (d>0)
        {
            x1=(-b-sqrt(d))/(2*a);
            x2=(-b+sqrt(d))/(2*a);
            cout<<min(x1,x2)<<endl<<max(x1,x2);
        }
    else if (d==0)
        cout<<-b/(2*a);
    else
        cout<<"NO SOLUTION";
    return 0;
}
