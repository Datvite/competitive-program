#include <bits/stdc++.h>
using namespace std;
string a,b;
int i,j,tong=1;
char n,c[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    for (int i=0;i<=a.size();i++)
    {
        c[i]=a[i];
    }
    sort (c,c+a.size());
    for (int i=0;i<=a.size();i++)
    {
        a[i]=c[i];
    }
    b=a;
    i=a.size()-1;
    while (true)
    {
        i=a.size()-1;
        while ((int)a[i]>=(int)a[i+1])
        {
            --i;
        }
        if (i<0)
             break;
        j=a.size();
        while (a[i]>=a[j])
            --j;
        n=a[i];
        a[i]=a[j];
        a[j]=n;
        reverse(a.begin()+i+1,a.end());
        tong++;
    }
    a=b;
    cout<<tong<<endl;
    cout<<a<<endl;
    i=a.size()-1;
    while (true)
    {
        i=a.size()-1;
        while ((int)a[i]>=(int)a[i+1])
        {
            --i;
        }
        if (i<0)
            return 0;
        j=a.size();
        while (a[i]>=a[j])
            --j;
        n=a[i];
        a[i]=a[j];
        a[j]=n;
        reverse(a.begin()+i+1,a.end());
        cout<<a<<endl;
    }
}
