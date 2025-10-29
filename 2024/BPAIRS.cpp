#include<bits/stdc++.h>
using namespace std;
int tong(int h)
{
    int c;
    while (h>0)
    {
        c=c+h%10;
        h/=10;
    }
    return c;
}
int main()
{
    int n,dem=0,k;
    cin>>n;
    int a,b[1000068];
    fill (b,b+n,0);
    for (int i=0;i<n;i++)
    {
        cin>>a;
        k=tong(a);
        dem=dem+b[k];
        b[k]++;
    }
    cout<<dem;
}
