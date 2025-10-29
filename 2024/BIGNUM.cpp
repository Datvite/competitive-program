#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("BIGNUM.INP","r",stdin);
    //freopen("BIGNUM.OUT","w",stdout);
    string a,b;
    cin>>a>>b;
    string c;
    int n=a.size();
    c.resize(n);
    while (b.size()<a.size())
        b='0'+b;
    int nho=0;
    int tong=0;
    for (int i=n-1; i>=0; i--)
    {
        tong=(a[i]-48)+(b[i]-48)+nho;
        if (tong>=10)
        {
            nho=1;
            tong=tong-10;
        }
        else
            nho=0;
        c[i]=(char)(tong+48);
    }
    if (nho==1)
        c='1'+c;
    cout<<c<<endl;
    int du=0,hieu=0;
    for (int i=n-1; i>=0; i--)
    {
        hieu=(a[i]-48)-(b[i]-48)-du;
        if (hieu<0)
        {
            hieu=hieu+10;
            du=1;
        }
        else
            du=0;
        c[i]=(char)(hieu+48);
    }
    int m=0;
    while (true)
    {
        if (c[m]=='0'&&m<n-1)
            m++;
        else
            break;
    }
    for (int i=m; i<n; i++)
        cout<<c[i];
}
