#include <bits/stdc++.h>
using namespace std;
long long a,ans,b,n,k,luu1,luu2;
bool sang[10000000];
void sang1()
{
    memset(sang,true,sizeof(sang));
    sang[0]=false;
   sang[1]=false;
    for (long long i=2; i*i<=10000000;++i)
    {
        if (sang[i]==true)
        {
            for (long long j=i*i;j<=10000000;j=j+i)
            {
                sang[j]=false;
            }
        }
    }
}

int main()
{
    freopen("FOURDIV.INP","r",stdin);
    freopen("FOURDIV.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sang1();
    for (int i=1;i<=n;i++)
        {
            cin>>k;
            luu2=k;
            k=1+k;
            while (sang[k]==false)
                k++;
            luu1=k;
            k=k+luu2;
            while (sang[k]==false)
                k++;
            luu2=k;cout<<luu1*luu2<<endl;
        }

}
