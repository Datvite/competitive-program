#include<bits/stdc++.h>
using namespace std;
struct he{
    long long k;
    long long b;
};
int a[1000006];
long long s[1000005];
he q[1000006];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen ("aaa.inp","r",stdin); freopen ("aaaac.out","w",stdout);
    long long p,l,o,duk,k1;
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=t;i++){
        cin>>q[i].k>>q[i].b;
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=t;i++){
        o=q[i].b%n;
        if(o==0) o=n;
        if(o+q[i].k-1>n){
        l=q[i].k-(n-o+1);
        duk=l%n;
        k1=l/n;
        p=s[n]*k1+s[duk]+(s[n]-s[o-1]);
        }
        else p=s[o+q[i].k-1]-s[o-1];

    cout<<p<<'\n';
    }
}
