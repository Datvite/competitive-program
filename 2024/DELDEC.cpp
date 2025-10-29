#include <bits/stdc++.h>
using namespace std;
void print_int128(__int128_t num) {
     if (num<0) {
        cout<<'-';
        num=-num;
    }
    string s;
    while(num>0){
        s.push_back(num%10+'0');
        num/=10;
    }
    if(s.empty()) s="0";
    reverse(s.begin(),s.end());
    cout<<s;
}
__int128_t skibidi(__int128_t n, __int128_t m, __int128_t z) {
    if (m==0) return 0;
    else{__int128_t t=skibidi(n,m/2,z);
    t%=z;
    t*=2;
    t%=z;
    if (m%2==0) return t;
    else return ((t+n%z)%z);
    }
}
long long t,m,n,z,j,i;
__int128_t khoc(__int128_t k) {
    if (k == 0) return 1;
    else{
    __int128_t x=khoc(k/2);
    x%=m;
    x=skibidi(x,x,m);
    if (k%2==0) return x;
    else return skibidi(x,10,m);
    }
}
__int128_t e,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    for(i=1;i<=t;i++){
    cin>>n>>m>>z;
        e=khoc(z-1);
        ans=(10*(((n%m)*(e%m))%m))/m;
        print_int128(ans);
        cout <<"\n";

    }
    return 0;
}
