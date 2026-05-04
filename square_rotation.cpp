//9c rotation of a square with predefined vertex
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    initwindow(900, 600);

    // Original square (LEFT SIDE)
    int x[4] = {150, 250, 250, 150};
    int y[4] = {200, 200, 300, 300};

    // Draw original square
    setcolor(WHITE);
    outtextxy(140, 170, "Before Rotation");
    for (int i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i+1)%4], y[(i+1)%4]);
    }

    // Rotation angle
    float angle = 45;
    float rad = angle * 3.1416 / 180;

    int xr[4], yr[4];

    // Apply rotation
    for (int i = 0; i < 4; i++) {
        xr[i] = x[i] * cos(rad) - y[i] * sin(rad);
        yr[i] = x[i] * sin(rad) + y[i] * cos(rad);
    }

    // SHIFT rotated square to RIGHT SIDE
    int shiftX = 600;  // horizontal shift

    setcolor(RED);
    outtextxy(500, 170, "After Rotation");

    for (int i = 0; i < 4; i++) {
        line(xr[i] + shiftX, yr[i], xr[(i+1)%4] + shiftX, yr[(i+1)%4]);
    }

    getch();
    closegraph();
    return 0;
}
