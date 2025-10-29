#include<bits/stdc++.h>
using namespace std;
long long tonguoc (long long n)
{
    long long tong=1;
    if (n==1)
        return 0;
    for (int i=2;i<=sqrt(n);i++)
        {
            if (n%i==0)
                {
                    if ((n/i)!=i)
                        tong=tong+i+n/i;
                    else
                        tong=tong+i;
                }

        }
    return tong;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PERS12.INP","r",stdin);
    freopen("PERS12.OUT","w",stdout);
    long long tong=0,t;
    long long n;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>t;
            if (tonguoc(t)==t)
                tong=tong+t;
        }
        cout<<tong;
}
