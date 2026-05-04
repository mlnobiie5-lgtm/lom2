//9a identity transformation
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    initwindow(900, 600, "Identity Transformation Demo");

    // ORIGINAL triangle (Before)
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw BEFORE (WHITE)
    outtextxy(100, 80, "Before Identity");
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Identity matrix
    int I[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Apply identity transformation
    int tx1 = x1 * I[0][0] + y1 * I[0][1] + I[0][2];
    int ty1 = x1 * I[1][0] + y1 * I[1][1] + I[1][2];

    int tx2 = x2 * I[0][0] + y2 * I[0][1] + I[0][2];
    int ty2 = x2 * I[1][0] + y2 * I[1][1] + I[1][2];

    int tx3 = x3 * I[0][0] + y3 * I[0][1] + I[0][2];
    int ty3 = x3 * I[1][0] + y3 * I[1][1] + I[1][2];

    // SHIFT to right for visual comparison
    int shift = 350;

    // Draw AFTER (RED)
    setcolor(RED);
    outtextxy(450, 80, "After Identity");

    line(tx1 + shift, ty1, tx2 + shift, ty2);
    line(tx2 + shift, ty2, tx3 + shift, ty3);
    line(tx3 + shift, ty3, tx1 + shift, ty1);

    getch();
    closegraph();
    return 0;
}
