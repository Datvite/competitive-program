#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CLASP.INP","r",stdin);
    freopen("CLASP.OUT","w",stdout);
    string n;
    int m;
    cin>>m;
    cin>>n;
    long long t=0,tong=0;
    for (int i=0;i<m;i++)
    {
        if (n[i]=='>')
            t++;
        if (n[i]=='<')
            tong=tong+t;
    }
    cout<<tong;
}
