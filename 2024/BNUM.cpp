#include<bits/stdc++.h>
using namespace std;
bool check(long long n)
{
    for (int i=2;i<=sqrt(n);i++)
        {
            if (n%i==0)
            return (false);
        }
    return (true);
}
long long tachso (long long n)
{
    long long tong=0,luu;
    while (n>0)
        {
            luu=n%10;
            n=n/10;
            tong=luu*luu+tong;
        }
    return tong;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BNUM.INP","r",stdin);
    freopen("BNUM.OUT","w",stdout);
    long long n,s;
    cin>>n;
    s=tachso(n);
    if (check(s))
        {
            cout<<1<<endl;
            cout<<s;
        }
    else
        {
            cout<<-1<<endl;
            cout<<s;
        }
}
