#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double a,b,c,p,s;
    cin>>a>>b>>c;
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<fixed<<setprecision(5);
    cout<<s;
    return 0;

}
