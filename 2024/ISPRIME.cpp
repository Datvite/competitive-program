#include<bits/stdc++.h>
using namespace std;
bool sang[1000068];
long long n,s[1000068],a,b;
void sang1()
{
    memset(sang,true,sizeof(sang));
    sang[1]=false;
    sang[0]=false;
    for (long long i=2; i*i<=1000068; i++)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i; j<=1000068; j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}
int main()
{
    //freopen("ISPRIME.INP","r",stdin);
    //freopen("ISPRIME.OUT","w",stdout);
    long long n;
    cin>>n;
    s[1]=0;
    s[0]=0;
    sang1();
    for (int i=2; i<=1000068; i++)
    {
        if (sang[i]==true)
        {
            s[i]=s[i-1]+1;
        }
        else
        {
            s[i]=s[i-1];
        }
    }
    for (int i=1; i<=n; i++)
    {
        cin>>a;
        b=2*a;
        cout<<s[b]-s[a]<<endl;
    }
    return 0;
}
