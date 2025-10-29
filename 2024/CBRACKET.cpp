#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CBRACKET.INP","r",stdin);
    freopen("CBRACKET.OUT","w",stdout);
    string n;
    int depth = 0;
    while (cin>>n)
    {
        depth=0;
        for (int i=0;i<n.size();i++)
        {
            if (n[i]=='(')
                    depth++;
            else
                    depth--;
            if (depth<0)
                break;
        }
        if (depth==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
