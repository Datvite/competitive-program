#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CNCH4.INP","r",stdin);
    freopen("CNCH4.OUT","w",stdout);
    string n;
    long long chu=0,so=0;
    getline(cin,n);
    for (int i=0;i<n.size();i++)
    {
        if (isalpha(n[i])) {
            chu++;
        } else if (isdigit(n[i])) {
            so++;
        }
    }
    cout<<chu<<" "<<so;
}
