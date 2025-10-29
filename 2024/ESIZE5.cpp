#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("ESIZE5.INP","r",stdin);
    freopen("ESIZE5.OUT","w",stdout);
    long double l,s,tong,delta,chieudai,chieurong;
    cin>>l>>s;
    tong=l/2;
    delta=tong*tong-4*s;
    cout<<fixed<<setprecision(2);
    if (delta>0)
    {
        chieudai=(-tong+sqrt(delta))/-2;
        chieurong=(-tong-sqrt(delta))/-2;
    }
    if (delta==0)
    {
        chieudai=tong/2;
        chieurong=tong/2;
    }
    cout<<min(chieudai,chieurong)<<endl;
    cout<<max(chieudai,chieurong);
}
