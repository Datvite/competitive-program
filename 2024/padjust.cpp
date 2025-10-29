#include<bits/stdc++.h>
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
using namespace std;
vector<int>ans;
int main()
{
    file("DELVALS")
    map<int,int>sang;
    long long n,k;
    int dem=0,dem1=0;
    cin>>n>>k;
    long long a[1000009],b[1000009],s;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<=k; i++)
    {
        cin>>s;
        sang[s]++;
    }
    for (int i=1; i<=n; i++)
    {
        if (sang[a[i]]!=0)
            sang[a[i]]--;
        else
            ans.push_back(a[i]);
    }
    for (auto i:ans)
        cout<<i<<" ";
}
