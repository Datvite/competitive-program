#include<bits/stdc++.h>
using namespace std;
int m=123456789;
long long Mul(long long a, long long b) {
    if (!b) return 0;
    long long x = Mul(a, b / 2);
    if (b % 2 == 0)
        return 2 * x % m;
    else
        return (2 * x + a) % m;
}
int main()
{
    long long n,x,ans=0;
    cin>>n>>x;
    long long a[1000068];
    for (int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=n; i>=0; --i)
    {
        ans=Mul(ans,x)+a[i];
        ans=ans%m;
    }
    cout<<ans%m;
}
