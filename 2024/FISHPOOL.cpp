#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define endl "\n"
using namespace std;
ll n,sang[1000068],k,x,y,q;
void sang1()
{
    for (int i=2; i<=1000; i++)
    {
        if (sang[i]==0)
        {
            for (int j=i; j<=1000*1000; j=j+i)
            {
                sang[j]++;
            }
        }
    }
}
int main()
{
    skibidi;
    sang1();
    cin>>n;
    ll maxn=LLONG_MIN,luu;
    for (int i=1;i<=n;i++)
        {
            cin>>x;
            if (sang[x]>maxn)
            {
                maxn=sang[x];
                luu=x;
            }

        }
    cout<<luu;
}
