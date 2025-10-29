#include <bits/stdc++.h>
using namespace std;
long long n,a,b,m=1;
long long dau(long long a)
{
    long long i=0;
    while(a!=0)
    {
        i=a%10;
        a/=10;
    }
    return i;
}
long long dem(long long a)
{
    long long i=0;
    while(a!=0)
    {
        i++;
        a=a/10;
    }
    return i;
}
long long nhanso (long long n,long long x)
{
    long long s=0;
    for (int i=1;i<=n;i++)
    {
        s=s*10+x;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DNM15.INP","r",stdin);
    freopen("DNM15.OUT","w",stdout);
    cin>>n;
    if (n<10)
        cout<<n;
    else if (dau(n)==1)
    {
        a=nhanso(dem(n),dau(n));
        b=nhanso(dem(n)-1,9);
        if (a>n)
            cout<<b;
        else
            cout<<a;
    }
    else
    {
        a=nhanso(dem(n),dau(n));
        b=nhanso(dem(n),dau(n)-1);
        if (a>n)
            cout<<b;
        else
            cout<<a;
    }
    return 0;
}
