#include<bits/stdc++.h>
using namespace std;
bool sang[1000068];
void sang1()
{
    for (long long i=1;i<=1000068;i++)
    {
        sang[i]=true;
    }
   sang[1]=false;
    for (long long i=2; i*i<=1000068;i++)
    {
        if (sang[i])
        {
            for (long long j=i*i;j<=1000068;j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
long long tong(long long n)
{
    long long s=0;
    for (long long i=1;i<=n;i++)
    {
        if (n%i==0&&sang[i])
            s=s+i;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SDPRI.INP","r",stdin);
    freopen("SDPRI.OUT","w",stdout);
    long long n,a[1000068];
    cin>>n;
    sang1();
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cout<<tong(a[i])%21111983<<endl;
    }
}
