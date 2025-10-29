#include<bits/stdc++.h>
using namespace std;
long long n;
bool check(string a,string b)
{
    return a+b>b+a;
}
vector<string>s;
string a;
int main()
{
    freopen("MAXNUM.INP","r",stdin);
    freopen("MAXNUM.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a;
        s.push_back(a);
    }
    sort(s.begin(),s.end(),check);
    for (auto i:s)
        cout<<i;
}
