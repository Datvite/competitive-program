#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,k;
    long double c,x,s;
    cin>>m>>n>>k;
    c=(double)m/k;
    x=(double)n/k;
    s=ceil(c)*ceil(x);
    cout<<s;
}

