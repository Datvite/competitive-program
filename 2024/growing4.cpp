#include<bits/stdc++.h>
#define vha ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define N 10000068
using namespace std;
ll n,kq;
int vh(vector<ll>&da){
    n=da.size();
    map<vector<ll>,ll>dp;
    function<ll(vector<ll>)>v=[&](vector<ll>p)->ll{
        if(dp.count(p)) return dp[p];
        ll mx=*max_element(p.begin(),p.end());
        for(int i=0;i<p.size()-1;i++){
            if(p[i]==p[i+1]){
                vector<ll>np=p;
                np[i]*=2;
                np.erase(np.begin()+i+1);
                mx=max(mx,v(np));
            }
        }
        return dp[p]=mx;
    };
    return v(da);
}
int main(){
    vha
    freopen("JOIN.inp","r",stdin);
    freopen("JOIN.out","w",stdout);
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    kq=vh(a);
    cout<<kq;
}
