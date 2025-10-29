#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SCPAIR5.INP","r",stdin);
    freopen("SCPAIR5.OUT","w",stdout);
    string s,p;
    getline(cin,s);
    getline(cin,p);
    long long l=s.size(),dem=0;
    for (long long i=0;i<l;i++)
    {
        if (s[i]==p[l-i-1])
            {
                dem++;
            }
    }
    cout<<dem;
}
