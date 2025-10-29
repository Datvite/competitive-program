#include <bits/stdc++.h>
using namespace std;
long long m,z,q;
map<int,int>a;
unsigned long long ans=1;
unsigned long long power(unsigned long long a,unsigned long long b)
{
    long long kq = 1;
    while (b > 0)
    {
        if (b % 2)
            kq = kq * a;
        a = a * a;
        b /= 2;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m;
    long long i=2;
    z=sqrt(m);
    while (i<=sqrt(m))
    {
        while (m%i==0)
        {
            m=m/i;
            a[i]++;
        }
        i++;
    }
    q=i;
    if (m>1)
        a[m]++;
    q=max(q,m);
    for (auto& i:a)
    {
        if (i.second%2==0)
            ans=ans*power(i.first,i.second);
        else
            ans=ans*power(i.first,i.second+1);
    }
    cout<<ans;
}
