#include <bits/stdc++.h>
using namespace std;
long long n,k;
bool sang[1000068];
void sang1()
{
    memset(sang,true,sizeof(sang));
    sang[0]=false;
    sang[1]=false;
    for (long long i=2; i*i<=1000068; ++i)
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
    //freopen("FOURDIV.INP","r",stdin);
    //freopen("FOURDIV.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sang1();
    for (int i=1; i<=n; i++)
    {
        cin>>k;
        while (sang[k]==false)
            k++;
        cout<<k<<"\n";
    }

}
