#include <bits/stdc++.h>
using namespace std;
long double n;
long double s=0;
void sub2()
{
    s=2*n/(n+1);
    cout<<fixed<<setprecision(8);
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("20CS.INP","r",stdin);
    freopen("20CS.OUT","w",stdout);
    cin>>n;
        sub2();

}
