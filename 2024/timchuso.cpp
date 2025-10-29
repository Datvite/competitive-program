#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,k;
long long x;
long long power(long long a, long long b, long long M)
{
    long long kq = 1;
    while (b > 0)
    {
        if (b % 2)
            kq = kq * a % M;
        a = a * a % M;
        b /= 2;
    }
    return kq;
}
long long ohno(long long a,long long b,long long c)
{
    long long x,ans;
    a=a%b;
    x=power(10,c-1,b);
    a=a*x;
    a=a%b;
    a=a*10;
    a=a/b;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b>>k;
        cout<<ohno(a,b,k)<<endl;
    }
}
