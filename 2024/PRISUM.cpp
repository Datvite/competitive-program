#include<bits/stdc++.h>
using namespace std;
bool check(long long n)
{
    for (long long i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PRISUM.INP","r",stdin);
    freopen("PRISUM.OUT","w",stdout);
    long long n,tong=0;
    cin>>n;
    for (long long i=2; i<=n; i++)
    {
        if (check(i))
            tong+=i;
    }
    if (check(tong))
        cout<<tong;
    else
        cout<<-1;
}
