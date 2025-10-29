#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
long long n,a[1000068],b[1000068],uoc[1000068],tong[1000068],x,y;
void souoc()
{
    for (long long i = 1; i <= 1000068; ++i)
        {
            for (long long j = i; j <= 1000068; j = j + i)
            {
                a[j]++;
                b[j] = b[j] + i;
            }
        }
}
int main()
{
    freopen("NATDIV.INP","r",stdin);
    freopen("NATDIV.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    souoc();
    uoc[0]=0;
    tong[0]=0;
    for (long long i=1;i<=1000000;i++)
       {
           uoc[i]=uoc[i-1]+a[i];
           tong[i]=tong[i-1]+b[i];
       }
    uoc[0]=0;
    tong[0]=0;
    for (int i=1;i<=n;i++)
       {
           cin>>x>>y;
           cout<<uoc[y]-uoc[x-1] <<" "<<tong[y]-tong[x-1]<<endl;
       }
}
