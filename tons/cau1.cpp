
#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

using namespace std;

#define int long long
const int N = 1e5 + 5;
int a[N];

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rand(int l, int h) /// hàm random từ l đến h
{
    return uniform_int_distribution<int>(l, h)(rng);
}

main()
{
    srand(time(0));
    skibidi for (int test = 1; test <= 100; test++)
    {
        ofstream cout(".inp");
        int n = rand(1, 10), Q = rand(1, 10);
        cout << n << endl;
        /// a[1] = 1e9 - n + 1, a[2] = 1e9 - n + 2, ... , a[n] = 1e9
        for (int i = 1; i <= n; i++)
        {
        }
        system(".exe");
        /// chạy code trâu
        system(".exe");

        /// fc = file compare
        if (system("fc GAME08.out GAME08TRAU.out") == 1)
            exit(0);
    }
}
