//9b.scaling transformation
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initwindow(800, 600, "Scaling Transformation");

    // Original triangle points
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Scaling factors
    float Sx = 2, Sy = 2;

    // Apply scaling
    int x1_new = x1 * Sx;
    int y1_new = y1 * Sy;
    int x2_new = x2 * Sx;
    int y2_new = y2 * Sy;
    int x3_new = x3 * Sx;
    int y3_new = y3 * Sy;

    // Draw scaled triangle
    setcolor(RED);
    line(x1_new, y1_new, x2_new, y2_new);
    line(x2_new, y2_new, x3_new, y3_new);
    line(x3_new, y3_new, x1_new, y1_new);

    getch();
    closegraph();
    return 0;
}
