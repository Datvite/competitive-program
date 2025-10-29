
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool go;

const int w = 20;
const int h = 20;

int x, y, fx, fy, sc;

int tx[100], ty[100];
int nt;

enum eDir {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDir d;

void Set() {
    go = false;
    d = STOP;
    x = w / 2;
    y = h / 2;
    fx = rand() % w;
    fy = rand() % h;
    sc = 0;
    nt = 0;
}

void Draw() {
    system("cls");

    for (int i = 0; i < w + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "*";
            else if (i == fy && j == fx)
                cout << "O";
            else {
                bool prt = false;
                for (int k = 0; k < nt; k++) {
                    if (tx[k] == j && ty[k] == i) {
                        cout << "*";
                        prt = true;
                    }
                }
                if (!prt)
                    cout << " ";
            }

            if (j == w - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < w + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << sc << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (d != RIGHT) d = LEFT;
            break;
        case 'd':
            if (d != LEFT) d = RIGHT;
            break;
        case 'w':
            if (d != DOWN) d = UP;
            break;
        case 's':
            if (d != UP) d = DOWN;
            break;
        case 'x':
            go = true;
            break;
        }
    }
}

void Logic() {
    int px = tx[0];
    int py = ty[0];
    int p2x, p2y;
    tx[0] = x;
    ty[0] = y;

    for (int i = 1; i < nt; i++) {
        p2x = tx[i];
        p2y = ty[i];
        tx[i] = px;
        ty[i] = py;
        px = p2x;
        py = p2y;
    }

    switch (d) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= w) x = 0; else if (x < 0) x = w - 1;
    if (y >= h) y = 0; else if (y < 0) y = h - 1;

    for (int i = 0; i < nt; i++)
        if (tx[i] == x && ty[i] == y)
            go = true;

    if (x == fx && y == fy) {
        sc += 10;
        fx = rand() % w;
        fy = rand() % h;
        nt++;
    }
}

int main() {
    Set();

    while (!go) {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }

    return 0;
}
