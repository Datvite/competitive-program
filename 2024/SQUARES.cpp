#include<bits/stdc++.h>
using namespace std;
long long sum(long long n)
{
    long long sum=0;
    sum=n*(n+1)*(2*n+1)/6;
    return sum;
}
int main()
{
    freopen("SQUARES.INP","r",stdin);
    freopen("SQUARES.OUT","w",stdout);
    long long n,t;
    cin>>n;
    t=sum(n);
    cout<<t/2013;
}
