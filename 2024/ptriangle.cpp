#include<bits/stdc++.h>
long long a[100][100],n;using namespace std;int main(){ios_base::sync_with_stdio(false);cin.tie(0);cin>>n;a[0][0]=0;a[0][1]=0;a[1][1]=1;cout<<1<<endl;for (int i=2;i<=n+1;i++){for (int j=1;j<=i;j++){a[i][j]=a[i-1][j-1]+a[i-1][j];cout<<a[i][j]<<" ";}cout<<endl;}}
