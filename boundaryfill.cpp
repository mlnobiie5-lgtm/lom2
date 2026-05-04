//boundary fill
#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// 4-connected Boundary Fill Algorithm
void boundaryFill(int x, int y, int fill_color, int boundary_color) {

    // Stop if outside screen
    if (x < 0 || y < 0 || x > getmaxx() || y > getmaxy())
        return;

    int current = getpixel(x, y);

    // Fill only if not boundary and not already filled
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);

        // Recursive calls (4-connected)
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    // Initialize graphics
    initwindow(800, 600, "Boundary Fill Algorithm");

    // Set boundary color
    setcolor(WHITE);

    // Define polygon
    int poly[10] = {200,150, 400,150, 400,300, 200,300, 200,150};

    // Draw polygon
    drawpoly(5, poly);

    // Fill inside polygon
    boundaryFill(250, 200, RED, WHITE);

    getch();
    closegraph();
    return 0;
}
