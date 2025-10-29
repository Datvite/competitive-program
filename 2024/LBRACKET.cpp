#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("LBRACKET.INP","r",stdin);
    freopen("LBRACKET.OUT","w",stdout);
    string n,cut;
    int k=0,maxv=0,t=0;
    cin>>n;
    for (int i=0; i<n.size(); i++)
    {
        int depth=0;
        for (int j=i; j<n.size(); j++)
        {
            if (n[j]=='(')
                depth++;
            if (n[j]==')')
                depth--;
            if (depth<0)
                break;
            if (depth==0)
                if (j-i+1>maxv)
                {
                    maxv=j-i+1;
                    k=i;
                    t=j;
                }
        }
    }
    cout<<maxv<<endl;
    cout<<k+1<<" ";
    cout<<t+1;
}
