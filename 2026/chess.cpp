#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Piece {
    int x, y, c;
};

// Kiểm tra xem trên đoạn nối giữa Tượng (tx, ty) và Vua (kx, ky) có quân cờ nào cản không
bool isBlocked(int tx, int ty, int kx, int ky, const vector<Piece>& bishops) {
    int dx = (kx > tx) ? 1 : -1;
    int dy = (ky > ty) ? 1 : -1;

    int curX = tx + dx;
    int curY = ty + dy;

    while (curX != kx && curY != ky) {
        for (const auto& b : bishops) {
            if (b.x == curX && b.y == curY) {
                return true; // Có quân cản
            }
        }
        curX += dx;
        curY += dy;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    vector<Piece> bishops;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y, c;
            cin >> x >> y >> c;
            bishops.push_back({x, y, c});
        } 
        else if (type == 2) {
            int x, y;
            cin >> x >> y;
            for (auto it = bishops.begin(); it != bishops.end(); ++it) {
                if (it->x == x && it->y == y) {
                    bishops.erase(it);
                    break;
                }
            }
        } 
        else if (type == 3) {
            int kx, ky, kc;
            cin >> kx >> ky >> kc;

            vector<pair<int, int>> attackers;

            for (const auto& b : bishops) {
                // Kiểm tra nằm trên cùng đường chéo
                if (abs(b.x - kx) == abs(b.y - ky)) {
                    // Kiểm tra xem có bị quân khác cản không
                    if (!isBlocked(b.x, b.y, kx, ky, bishops)) {
                        attackers.push_back({b.x, b.y});
                    }
                }
            }

            // Sắp xếp tăng dần theo x, nếu x bằng nhau thì tăng dần theo y
            sort(attackers.begin(), attackers.end());

            // In kết quả
            cout << attackers.size();
            for (const auto& p : attackers) {
                cout << " " << p.first << " " << p.second;
            }
            cout << "\n";
        }
    }

    return 0;
}