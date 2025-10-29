#include <bits/stdc++.h>
using namespace std;
long long n,a[1000006],i,gmax=LLONG_MAX,luu1,luu2,luu3,gmin=LLONG_MAX;
struct vt
{
    long long so;
    long long vt;
};
vt x,y,z;
void sub1()
{
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++)
            for(int k=j+1;k<=n;k++){
                if((a[k]+a[j]-a[i])<gmin)
                   {
                    gmin=a[k]+a[j]-a[i];
                    luu1=i;luu2=j;luu3=k;
                }
            }
            cout<<luu1<<" "<<luu2<<" "<<luu3;
}
void sub2()
{
    y.so=a[n-1];
    z.so=a[n];
    y.vt=n-1;
    z.vt=n;
    if(y.so<z.so)
        {
            swap(y.so,z.so);
            swap(y.vt,z.vt);
    }
    for(i=n-3;i>=1;i--){
        if(a[i+1]<z.so){
            y.so=z.so;
            z.so=a[i+1];
            y.vt=z.vt;
            z.vt=i+1;
        }
        else if(a[i+1]<y.so)
            {
                y.so=a[i+1];
                y.vt=i+1;
            }
        if (z.so+y.so-a[i]<gmax)
            {
                gmax=z.so+y.so-a[i];
                luu1=i;
                luu2=z.vt;
                luu3=y.vt;
            }
        }
    if (luu2>luu3)
        swap(luu2,luu3);
    cout<<luu1<<" "<<luu2<<" "<<luu3;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("20SPO.INP","r",stdin);
    freopen("20SPO.OUT","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    if (n<=1000)
        sub1();
    else
        sub2();
}
