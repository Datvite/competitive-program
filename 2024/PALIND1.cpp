#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("PALIND1.INP","r",stdin);
    freopen("PALIND1.OUT","w",stdout);
    string n;
    int t=-1;
    bool h[1000];
    while (cin>>n)
    {
        t++;
        for (int i=0;i<n.size();i++)
        {
            if (n[i]!=n[n.size()-i-1])
                {
                    h[t]=false;
                    break;
                }
            else
                h[t]=true;
        }
    }
    for (int i=0;i<=t;i++)
    {
        if (h[i])
            cout<<"TRUE"<<endl;
        else
            cout<<"FALSE"<<endl;
    }
}
