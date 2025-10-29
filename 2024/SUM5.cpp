#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define endl "\n"
using namespace std;
ll n,k,a[1000068];
int main()
{

    skibidi;
    file("SUM5")
    cin>>n;
    if (n%5==0&&n/5-2>=0)
        cout<<n/5-2<<" "<<n/5-1<<" "<<n/5<<" "<<n/5+1<<" "<<n/5+2;
    else
        cout<<-1;
}
