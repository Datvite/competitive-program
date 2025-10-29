#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],s=2009;
void sub2()
{
    if (n%2==0)
        s=s+(-1)*n/2;
    else
        s=s+(-1)*(n-1)/2+n;
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("16CS.INP","r",stdin);
    //freopen("16CS.OUT","w",stdout);
    cin>>n;
    sub2();
}
