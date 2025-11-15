#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<vector<int>> diff(n+2, vector<int>(m+2, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] != 'g') continue;

                int x = i, y = j;

                // 1) Top edge: x_center = x - k
                int xc = x - k;
                if(0 <= xc && xc < n){
                    int ly = y - k, ry = y + k;
                    ly = max(ly, 0);
                    ry = min(ry, m-1);
                    if(ly <= ry){
                        diff[xc][ly]++;
                        diff[xc][ry+1]--;
                    }
                }

                // 2) Bottom edge: x_center = x + k
                xc = x + k;
                if(0 <= xc && xc < n){
                    int ly = y - k, ry = y + k;
                    ly = max(ly, 0);
                    ry = min(ry, m-1);
                    if(ly <= ry){
                        diff[xc][ly]++;
                        diff[xc][ry+1]--;
                    }
                }

                // 3) Left edge: y_center = y - k
                int yc = y - k;
                if(0 <= yc && yc < m){
                    int lx = x - k, rx = x + k;
                    lx = max(lx, 0);
                    rx = min(rx, n-1);
                    for(int xx = lx; xx <= rx; xx++){
                        diff[xx][yc]++;
                        diff[xx][yc+1]--;
                    }
                }

                // 4) Right edge: y_center = y + k
                yc = y + k;
                if(0 <= yc && yc < m){
                    int lx = x - k, rx = x + k;
                    lx = max(lx, 0);
                    rx = min(rx, n-1);
                    for(int xx = lx; xx <= rx; xx++){
                        diff[xx][yc]++;
                        diff[xx][yc+1]--;
                    }
                }
            }
        }

        // prefix sum
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                diff[i][j] += diff[i][j-1];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == '.')
                    ans = max(ans, diff[i][j]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
