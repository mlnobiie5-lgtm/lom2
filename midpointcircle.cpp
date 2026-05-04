// 4. Draw a circle using Midpoint Circle Algorithm

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// Function to plot all 8 symmetric points
void drawCirclePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE); // 1
    putpixel(xc - x, yc + y, WHITE); // 2
    putpixel(xc + x, yc - y, WHITE); // 3
    putpixel(xc - x, yc - y, WHITE); // 4
    putpixel(xc + y, yc + x, WHITE); // 5
    putpixel(xc - y, yc + x, WHITE); // 6
    putpixel(xc + y, yc - x, WHITE); // 7
    putpixel(xc - y, yc - x, WHITE); // 8
}

// Midpoint Circle Algorithm
void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter

    while (x <= y)
    {
        drawCirclePoints(xc, yc, x, y);

        if (p < 0)
        {
            // Midpoint inside circle
            p = p + 2 * x + 3;
        }
        else
        {
            // Midpoint outside or on circle
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r;

    cout << "Enter origin (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    midpointCircle(xc, yc, r);

    // Display origin text
    char text[50];
    sprintf(text, "Origin (%d,%d)", xc, yc);
    outtextxy(xc + 10, yc + 10, text);

    getch();
    closegraph();
    return 0;
}
