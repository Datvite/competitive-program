#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("TIETKIEM1.INP","r",stdin);
    freopen("TIETKIEM1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n;
    long double a;
    cin>>a>>n;
    for (int i=1;i<=n;i++)
        a=a+a*0.3/100;
    cout<<fixed<<setprecision(3);
    cout<<a;
}
