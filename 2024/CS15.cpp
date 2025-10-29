#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CS15.INP","r",stdin);
    freopen("CS15.OUT","w",stdout);
    long long n,m,a,b,c;
    cin>>n;
    a=n;
    b=n+1;
    c=n+2;
    if (a%3==0)
    {
        a=a/3;
    }
    else if (b%3==0)
    {
        b=b/3;
    }
    else if (c%3==0)
    {
        c=c/3;
    }
    a=a%2020;
    b=b%2020;
    c=c%2020;
    m=a*b*c%2020;
    cout<<m;
}
