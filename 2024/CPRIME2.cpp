#include <bits/stdc++.h>
using namespace std;
long long a,ans,b,n,k;
bool sang[10000000];
int s[10000000];
void sang1()
{
    memset(sang,true,sizeof(sang));
    sang[0]=false;
    sang[1]=false;
    sang[2]=true;
    for (int i=4; i<10000007; i=i+2)
        sang[i]=false;
    for (long long i=3; i*i<10000007; i=i+2)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i; j<10000007; j=j+i)
            {
                sang[j]=false;
            }
        }
    }
    s[0]=0;
    s[1]=0;
    for (long long i=2; i<10000007; ++i)
    {
        if (sang[i])
            s[i]=s[i-1]+1;
        else
            s[i]=s[i-1];
    }
}

int main()
{
    freopen("CPRIME.INP","r",stdin);
    freopen("CPRIME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sang1();
    for (int i=1; i<=n; ++i)
    {
        cin>>a>>b;
        k=s[b]-s[a-1];
        cout<<k<<"\n";
    }
}
