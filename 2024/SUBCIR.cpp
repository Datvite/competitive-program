#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SUBCIR.INP","r",stdin);
    freopen("SUBCIR.OUT","w",stdout);
    long long n,k,b,m,tong=0;
    cin>>n>>m;
    long long a[3000000],s[3000000];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    long long t1,t2,t3,cnt;
    for (int i=1; i<=m; i++)
    {
        cin>>k>>b;
        b=b%n;
        if (b==0)
            b=n;
        if (b+k-1<=n)
            cout<<s[b+k-1]-s[b-1]<<endl;
        else
        {
            t1=s[n]-s[b-1];
            cnt=k-(n-(b-1));
            t2=(cnt/n)*s[n];
            t3=s[cnt%n];
            cout<<t1+t2+t3<<endl;
        }
    }
}
