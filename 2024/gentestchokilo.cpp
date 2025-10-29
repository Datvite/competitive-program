#include <bits/stdc++.h>
using namespace std;
#define int long long
const string NAME = "MDL";
const int NTEST = 50;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
  return uniform_int_distribution<int> (l, h) (rd);
}
void MakeTest(){
  ofstream inp((NAME + ".inp").c_str());
  int n=Rand(-1e9,1e9),q=Rand(-1e9,1e9),c=Rand(1,31);
  inp<<n<<' '<<q<<'\n';
  inp<<c;
  inp.close();
}

signed main() {
  srand(time(NULL));
    MakeTest();
}
