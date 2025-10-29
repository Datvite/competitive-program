#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int max_value=max({a,b,c,d});
  int min_value=min({a,b,c,d});
  cout<<min_value<<" "<<max_value;
  return 0;
}


