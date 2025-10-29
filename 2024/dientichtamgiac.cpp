#include <bits/stdc++.h>
using namespace std;
long double n,a,b,c,d,t,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b;
    if (a==0&&b!=0)
        cout<<"VO NGHIEM";
    else if (b==0)
        cout<<"VO SO NGHIEM";
    else
        {
            ans=-b/a;
            cout<<fixed<<setprecision(5)<<ans;
        }
}
