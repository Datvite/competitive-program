#include <bits/stdc++.h>
using namespace std;
string n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=n.size()-1; i>=0; i--)
    {
        if (i==0&&n[i]=='1')
        {
            cout<<"NOTAVAILABLE";
            return 0;
        }
        if (n[i]=='1')
            n[i]='0';
        else
        {
            n[i]='1';
            break;
        }

    }
    cout<<n;
}
