#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MWORDS.INP","r",stdin);
    freopen("MWORDS.OUT","w",stdout);
    string n;
    getline(cin,n);
    int t=0,maxv=0;
    for (int i=0;i<n.size();i++)
    {
        if (n[i]!=' ')
        {
            t++;
            maxv=max(maxv,t);
        }
        else
        {
            t=0;
        }
    }
    cout<<maxv;
}
