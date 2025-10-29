#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CHKSTR.INP","r",stdin);
    freopen("CHKSTR.OUT","w",stdout);
    string n;
    int t;
    cin>>t;
    getline(cin,n);
    int depth=0;
    for (int i=0; i<t; i++)
    {
        getline(cin,n);
        depth=0;
        for (int j=0; j<n.size(); j++)
        {
            if (n[j]=='(')
                depth++;
            if (n[j]==')')
                depth--;
            if (depth<0)
                break;
            if (n[j]!='('&&n[j]!=')')
            {
                depth=-1;
                break;
            }
        }
        if (depth==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
