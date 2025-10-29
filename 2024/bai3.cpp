#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1e6+69;
ll a[N],n,l[N],r[N],res[N],q,t;
stack<int>st;
pair<int,int>a1[N];
void sol()
{
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        while (!st.empty()&&a[st.top()]<=a[i])
            st.pop();
        if (st.empty())
            l[i]=0;
        else
            l[i]=st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i=n; i>=1; i--)
    {
        while (!st.empty()&&a[st.top()]<=a[i])
            st.pop();
        if (st.empty())
            r[i]=n+1;
        else
            r[i]=st.top();
        st.push(i);
    }
    for (int i=1; i<=n; i++)
        a1[i]= {a[i],r[i]-l[i]-1};
    sort(a1+1,a1+n+1);
    for (int i=1; i<=n; i++)
        if (a1[i].se<a1[i-1].se)
            a1[i].se=a1[i-1].se;
    for (int i=1; i<=n; i++)
        a[i]=a1[i].fi,res[i]=a1[i].se;
}
main()
{
    skibidi;
    file("CPACK")
    cin>>n>>q;
    sol();
    while (q--)
    {
        cin>>t;
        auto id=upper_bound(a+1,a+n+1,t)-a-1;
        cout<<res[id]<<endl;
    }
}

