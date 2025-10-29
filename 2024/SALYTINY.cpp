#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a>c&&b>c||a<c&&b<c)
    {
        cout<<0;
        return 0;
    }
    if (a>b)
        switch(a,b);
    int t=0,dem=a;
    t++;
    while ((double)dem/t!=c)
    {
        if ((double)dem/t>c)
        {
            dem=dem+a;
            t++;
        }
        if ((double)dem/t<c)
        {
            dem=dem+b;
            t++;
        }
    }
    cout<<t;
}
