#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double a,b;
    cin>>a>>b;
    cout<<fixed<<setprecision(5);
    if (a!=0&&b!=0)
        cout<<-b/a;
    if (a==0&&b!=0)
        cout<<"Vo nghiem";
    if (a==0&&b==0)
        cout<<"Vo so nghiem";
    return 0;
}
