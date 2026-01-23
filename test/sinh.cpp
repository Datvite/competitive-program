#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
    return uniform_int_distribution<int> (l, r) (rng);
}
main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 100;
    for (int i = 1; i <= t; i++)
        {
            ofstream cout("trau.inp");
            int a = rand(1, 1e5), b = rand(1, 1e5);
            cout << a << " " << b << endl;
            system("trau.exe");
            system("full.exe");
            if (system("fc trau.out full.out") == 1)
                exit(0);
        }
}
