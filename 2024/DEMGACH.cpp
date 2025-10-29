#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DEMGACH.INP","r",stdin);
    freopen("DEMGACH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,m,den,trang;
    cin>>n>>m;
    den=n*2+(m-2)*2;
    trang=n*m-n*2-(m-2)*2;
    cout<<den<<" "<<trang;
    return 0;
}
