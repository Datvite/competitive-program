#include <bits/stdc++.h>
using namespace std;
long long s=0;
string n;
void sub1()
{
    for (int i=0;i<n.size();i++)
        {
            s=s+(n[i]-48);
        }
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("18SDI.INP","r",stdin);
    freopen("18SDI.OUT","w",stdout);
    cin>>n;
        sub1();
}
