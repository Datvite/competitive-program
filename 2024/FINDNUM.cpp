#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
long long n,a[1000000];
int d[10000007],maxn=-10;
map<long long,long long>m;
map<long long,bool>m1;
void sangnt()
{
    long long i,j;
    for (i = 2; i <= 1e7; ++i)
        d[i] = i;
    for (i = 2; i * i <=1e7; ++i)
        if (d[i] == i)
            for (j = i * i; j <= 1e7; j += i)
                if (d[j] == j)
                    d[j] = i;
}

int main()
{
    freopen("FINDNUM.INP","r",stdin);
    freopen("FINDNUM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sangnt();
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        m1[a[i]]=true;
        while (a[i]>1)
        {
            m[d[a[i]]]++;
            a[i]/=d[a[i]];
            maxn=max(maxn,d[a[i]]);
        }
    }
    for (auto& i:m)
    {
        long long x=i.first;
        long long y=i.first;
        while (i.second>0)
        {

            m1[x]=true;x=x*y;
            i.second--;
        }
    }
    long long i=2;
    while (true)
    {

        if (m1[i]==false)
        {
            cout<<i;
            break;
        }
        i++;
    }
}
