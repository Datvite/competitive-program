#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("TWGOATS.INP","r",stdin);
    freopen("TWGOATS.OUT","w",stdout);
    string n;
    cin>>n;
    long long depth=0,tong=0;
    bool t=false;
    for (int i=0; i<n.size(); i++)
    {
        if (n[i]=='>')
        {
            if (t==false)
                depth=0;
            depth++;
            tong++;
            t=true;
        }
        if (t==false)
        {
            if (n[i]=='<')
            {
                depth++;
                tong++;
            }
        }
        else
        {
            if (n[i]=='<')
                {
                    depth--;
                    tong--;
                }
        }
        if (depth==0)
        {
            t=false;
        }
    }
    cout<<tong;
}
