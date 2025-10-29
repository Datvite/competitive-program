#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll n;
int main()
{
    skibidi;
    file("JOIN")
    cin>>n;
    vector<ll> a(n),b(n);
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    b=a;
    while (true)
    {
        bool check=false;
        vector<ll> a1;
        for (int i=0; i<a.size();)
        {
            if (i<a.size()-1&&(a[i]==a[i+1]))
            {
                a1.push_back(a[i]*2);
                i+=2;
                check=true;
            }
            else
            {
                a1.push_back(a[i]);
                i++;
            }
        }
        a=a1;
        if (check==false)
            break;
    }
    ll ans=0;
    ans=max(ans,*max_element(a.begin(),a.end()));
     while (true)
    {
        bool check=false;
        vector<ll> a1;
        for (int i=b.size()-1; i>0;)
        {
            if (i>0&&(b[i]==b[i-1]))
            {
                a1.push_back(b[i]*2);
                i-=2;
                check=true;
            }
            else
            {
                a1.push_back(b[i]);
                i--;
            }
        }
        b=a1;
        if (check==false)
            break;
    }
    ans=max(ans,*max_element(b.begin(),b.end()));
    cout<<ans;
}
