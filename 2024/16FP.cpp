#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],gmax=LLONG_MIN,gmin=LLONG_MAX,luu=0,m=0;
bool sang[1000000];
bool snt(long long n)
{
    if(n<2)
        return(false);
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
        return(false);
    return(true);
}
void sang1()
{
    for (long long i=1;i<=1000000;i++)
    {
        sang[i]=true;
    }
   sang[1]=false;
    for (long long i=2; i*i<=1000000;i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i;j<=1000000;j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
void sub2()
{
    for (int i=1;i<=n;i++)
        {
            if (snt(a[i]))
            {
                luu=i;
                break;
            }
        }
    cout<<luu;
}
void sub3()
{
    for (int i=1;i<=n;i++)
        {
            if (snt(a[i]))
            {
                luu=i;
                break;
            }
        }
    cout<<luu;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("16FP.INP","r",stdin);
    freopen("16FP.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        gmin=min(a[i],gmin);
        gmax=max(a[i],gmax);
    }
    if (n>=1000000)
        {
            sub2();
        }
    else if (n<=1000&&gmin<=-1000000||gmax>=1000000)
        sub3();
    else
        sub2();
}
