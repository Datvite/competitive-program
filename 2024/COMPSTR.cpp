#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("COMPSTR.INP","r",stdin);
    freopen("COMPSTR.OUT","w",stdout);
    string n,t;
    int m=0;
    cin>>n;
    t[0]=n[0];
    for (int i=0;i<n.size();i++)
    {
        if (n[i]==n[i-1])
            continue;
        cout<<n[i];
    }
}
