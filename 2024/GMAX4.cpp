#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,c,s2=0;
  cin>>a>>b>>c;
  int max_value=max({a,b,c});
  int min_value=min({a,b,c});
  s2=a+b+c-max_value-min_value;
  cout<<min_value<<" "<<s2<<" "<<max_value;
  return 0;
}
