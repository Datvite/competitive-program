#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],luu1,luu2;
bool sang[1000068];
void sang1()
{
    for (long long i=1; i<=1000000; i++)
    {
        sang[i]=true;
    }
    sang[1]=false;
    for (long long i=2; i*i<=1000000; i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i; j<=1000000; j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
long long doiso (long long n)
{
    long long somoi=0;
    while (n>0)
    {
        somoi=somoi*10+n%10;
        n=n/10;
    }
    return somoi;
}
bool snt (long long n)
{
    if (n<2)
        return false;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    freopen("PPRIME.INP","r",stdin);
    freopen("PPRIME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sang1();
    for (int i=2; i<=n; i++)
    {
        if (i<=1e6&&doiso(i)<=1e6)
        {
                if (sang[i]&&sang[doiso(i)])
                    cout<<i<<" ";
        }
        else
        {
            if (snt(i)&&snt(doiso(i)))
                cout<<i<<" ";
        }
    }
}
