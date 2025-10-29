#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("LENGTH.INP","r",stdin);
    freopen("LENGTH.OUT","w",stdout);
    long double a,b,c,s,s1,chuvi,k,s2;
    cin>>a>>b>>c>>s;
    chuvi=(a+b+c)/2;
    s1=sqrt(chuvi*(chuvi-a)*(chuvi-b)*(chuvi-c));
    s2=s1-s;
    k=sqrt(s1/s2);
    cout<<fixed<<setprecision(2);
    cout<<a/k;
}
