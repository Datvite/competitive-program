#include <bits/stdc++.h>
using namespace std;
string a;
int i,j;
char n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    i=a.size()-1;
    while ((int)a[i]>=(int)a[i+1])
    {
        --i;
    }
    if (i<0)
    {
        cout<<"NOTAVAILABLE";
        return 0;
    }
    j=a.size();
    while (a[i]>=a[j])
        --j;
    n=a[i];
    a[i]=a[j];
    a[j]=n;
    reverse(a.begin()+i+1,a.end());
    cout<<a;
}
