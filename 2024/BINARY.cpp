#include<bits/stdc++.h>
using namespace std;
long long a[1000068],n,t,nho=0,dem=0,tong=0;
int main()
{
    if (fopen("BINARY.INP","r"))
    {
        freopen("BINARY.INP","r",stdin);
        freopen("BINARY.OUT","w",stdout);
    }
    cin>>n;
    long long i=1;
    while (n>0)
    {
        a[i]=n%2;
        n=n/2;
        i++;
    }
    for (int j=i-1; j>=1; j--)
        cout<<a[j];
}
