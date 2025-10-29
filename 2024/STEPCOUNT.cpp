#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    double coun;
    cin>>n>>m;
    if (n%2!=0)
        n++;
    n=n/2;
    while (n>=0)
    {
        if (n%m==0)
            break;
        n++;
    }
    cout<<n;
}
