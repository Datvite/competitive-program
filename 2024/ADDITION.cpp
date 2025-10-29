#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
long long n,d,k;
long long dem (long long n)
{
    long long ans=0;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            ans++;
            while (n%i==0)
                n=n/i;
        }
    }
    if (n!=1)
        ans++;
    return ans;

}
long long sang[1000060];
void sang1()
{
    for (long long i=2; i*i<=1000060; i++)
    {
        if (sang[i]==0)
        {
            sang[i]=1;
            for (long long j=i*i; j<=1000060; j=j+i)
            {
                sang[j]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long b;
    if (n<=1e5)
    {
        for (int i=1; i<=n; i++)
        {
            cin>>b;
            cout<<dem(b)<<endl;
        }
    }
    else
    {
        sang1();
        for (int i=1; i<=n; i++)
        {
            cin>>b;
            cout<<sang[b]<<endl;
        }
    }
}
