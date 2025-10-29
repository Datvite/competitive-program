#include<bits/stdc++.h>
using namespace std;
struct rep
{
    int l;
    int r;
};
bool cmp(rep x, rep y){
    if(x.r<y.r) return true;
    if(x.r==y.r&&x.l>y.l) return true;
    return false;
}
rep a[100005];
long long b[1000005];
map<int,int>m;
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
       cout.tie(NULL);
if(fopen("rep.inp","r")){
    freopen("rep.inp","r",stdin);
     freopen("rep.out","w",stdout);
}
    int n;
    int R,L;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+n+1,cmp);
    m[a[1].r-1]++; L=a[1].r-1;
    m[a[1].r]++;    R=a[1].r;
    for(int i=2;i<=n;i++){
        if(R>=a[i].l&&L<a[i].l){
            m[a[i].r]++;
            L=R; R=a[i].r;
        }
        if(R<a[i].l){
            L=a[i].r-1;
            R=a[i].r;
            m[L]++;
            m[R]++;
        }
    }
    cout<<m.size()<<'\n';
    for(auto x:m) cout<<x.first<<" ";
}
