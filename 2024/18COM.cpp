#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],gmax=LLONG_MIN,tong=0,k;
bool sang[1000012];
void sang1()
{
    memset(sang,true,sizeof(sang));
    sang[1]=false;
    sang[0]=false;
    for (long long i=2; i<=sqrt(1000012); i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i; j<=1000012; j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
bool check(long long n)
{
    for (int i=2; i<=sqrt(n);i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
void sub1()
{
    for (int i=1; i<=n; i++)
        {
            if (check(a[i])==false&&a[i]>3)
            tong=tong+a[i];
        }
    cout<<tong;
}
void sub3()
{
    for (int i=1; i<=n; i++)
        {
            if (sang[a[i]]==false&&a[i]>3)
            {
                tong=tong+a[i];
            }
        }
    cout<<tong;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("18COM.INP","r",stdin);
    //freopen("18COM.OUT","w",stdout);
    cin>>n;

    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if (n<=1000)
    {
            sub1();
    }
    else
    {
        sang1();
        sub3();
    }
}
