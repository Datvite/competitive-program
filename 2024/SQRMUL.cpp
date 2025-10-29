#include <bits/stdc++.h>
long long m=1;
using namespace std;
long long n,a[1000008],d[1000008],ans=0,dem=0,t,k,z;
map<long long,int>dem1;
void sangnt()
{
    long long i,j;
    for (i = 2; i <= 1000000; ++i)
        d[i] = i;
    for (i = 2; i * i <=1000000; ++i)
        if (d[i] == i)
            for (j = i * i; j <= 1000000; j += i)
                if (d[j] == j)
                    d[j] = i;

}
long long power(long long a, long long n)
{
    if(n == 0)
    {
        return 1ll;
    }
    long long k = power(a,n/2);
    k=k%m;
    if(n % 2 == 1)
    {
        return k * k*a ;
    }
    else
    {
        return k * k;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("SQRMUL.INP","r",stdin);
    //freopen("SQRMUL.OUT","w",stdout);
    sangnt();
    cin>>n;
    for (int aa=1; aa<=n; ++aa)
    {
        cin>>t;
        for (int i=1; i<=t; ++i)
        {
            cin>>a[i];
            z=abs(a[i]);
            dem=0;
            ans=d[z];
            if (z!=1)
            {
                while (z>1)
                {
                    if (ans==d[z])
                        dem++;
                    else
                        dem=1;
                    if (dem>dem1[d[z]])
                    {
                        dem1[d[z]]=dem;
                    }
                    ans=d[z];
                    z=z/d[z];
                }
            }
        }
        ans=1;
        for (auto& i:dem1)
        {
            if (i.second%2==0)
                k=i.second/2;
            else
                k=i.second/2+1;
            k=power(i.first,k);
            ans=ans*k;
        }
        cout<<(ans*ans)<<endl;
    }
}
