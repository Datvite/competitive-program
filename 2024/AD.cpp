#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("AD.INP","r",stdin);
    freopen("AD.OUT","w",stdout);
    string a,b;
    cin>>a>>b;
    int d1[30],d2[30];
    fill(d1,d1+30,0);
    fill(d2,d2+30,0);
    for (int i=0;i<a.size();i++)
    {
        d1[a[i]-'a']++;
    }
    for (int i=0;i<b.size();i++)
    {
        d2[b[i]-'a']++;
    }
    int tong=0;
    for (int i=0;i<=25;i++)
    {
        tong=tong+abs(d1[i]-d2[i]);
    }
    cout<<tong;
}
