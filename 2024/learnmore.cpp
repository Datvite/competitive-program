#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    skibidi;
    file("CINT");
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b < c || d < a)
        cout<<b-a+d-c+2;
    else
    {
        a= min(a,c);
        b= max(b,d);
        cout<<b-a+1;
    }
}
