#include <bits/stdc++.h>
using namespace std;
long long n,kq,b,c,dem;
long long sochu (long long n)
{
    while (n>0)
    {
        dem=dem*10+1;
        n=n/10;
    }
    return dem;
}
long long sodau (long long n)
{
    int dem=0;
    while (n>=10)
    {
        n=n/10;
    }
    return n%10;
}
int main()
{
    cin>>n;
    b=sochu(n);
    c=sodau(n);
    kq=b*c;
    if (n<10)
        {
            cout<<n;
            return 0;
        }
    if (kq<=n)
        cout<<kq;
    else if (c!=1)
        cout<<b*(c-1);
    else
        cout<<(b/10)*9;
}
