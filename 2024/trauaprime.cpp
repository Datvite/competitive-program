#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;
int n;
int a[N];
vector < int > p1 , p2 , p3;
bool prime[N];
int cnt[N];

void sang(int n)
{
    for(int i = 2 ; i <= n ; i++)
        prime[i] = true;

    for(int i = 2 ; i <= sqrt(n) ; i++)
        if(prime[i] == true)
        {
            for(int j = i * i ; j <= n ; j += i)
                prime[j] = false;
        }
}


main()
{
    freopen("aprime.inp","r",stdin);
    freopen("trauaprime.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    sang(1e6);

    /// prime[i] = true  -> i là số nguyên tố
    ///          = false -> i không phải số nguyên tố

    for(int i = 2 ; i <= 1 ; i++)
        if(prime[i] == true)
            p1.push_back(i);

    for(int i = 2 ; i <= 1 ; i++)
        if(prime[i] == true)
            p2.push_back(i);

    for(int i = 2 ; i <= 1 ; i++)
        if(prime[i] == true)
            p3.push_back(i);


    for(auto x: p2)
        for(auto y: p3)
            if(x * x + y * y * y <= 1e5)
                cnt[x * x + y * y * y]++;
    /// số lượng số nguyên tố <= 100 * số lượng nguyên tố <= 1000
    cin >> n;


    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        /// p2 ^ 2 + p3 ^ 3 = ai - p1
        int ans = 0;
        for(auto p: p1)
            if(a[i] - p >= 0)
                ans += cnt[a[i] - p];
        cout << ans << "\n";
    }

    /// n * số lượng số tố <= 1e6

    /// 1000 * 78498 ~ 8e7
}
