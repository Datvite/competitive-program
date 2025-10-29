#include<bits/stdc++.h>
using namespace std;
bool sang[1000068];
void sang1()
{
    for (long long i=1;i<=1000068;i++)
    {
        sang[i]=true;
    }
    sang[0]=false;
    sang[1]=false;
    for (long long i=2; i*i<=1000068;i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i;j<=1000068;j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CPPRI3.INP","r",stdin);
    freopen("CPPRI3.OUT","w",stdout);
    long long n,m,dem=0;
    cin>>n>>m;
    sang1();
    for (int i=m;i<=n;i++)
        {
            if (sang[i]&&sang[i-m])
                {
                    dem++;
                }
        }
    cout<<dem;
}
