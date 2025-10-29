#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long double a1,a2,b1,b2,c1,c2,x=0,y=0,m,n,k;
    cin>>k;
    while (k--)
    {
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        if (a1!=0)
        {
            m=(c2-((a2*c1)/a1))*a1;
            n=-b1*a2+b2*a1;
            y=m/n;
            x=(c1-b1*y)/a1;
        }
        else
        {
            m=(c2-((a2*c1)/1))*a1;
            n=-b1*a2+b2*a1;
            y=m/n;
            x=(c1-b1*y)/1;
        }
        if (a1==0&&b2==0)
        {
            if (a1==0&&b1==0&&c1==0)
            {
                cout<<"INFINITE"<<"\n";
            }
            else if (a1==0&&b1==0)
            {
                cout<<"NO SOLUTION"<<"\n";
            }
            cout<<c2<<" "<<c1<<"\n";
        }
        else
        {
            if (n!=0)
                cout<<x<<" "<<y<<"\n";
            else if (n==0)
                cout<<"NO SOLUTION"<<"\n";
            else
                cout<<"INFINITE"<<"\n";
        }
    }
}
