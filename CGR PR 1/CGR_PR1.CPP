#include <iostream.h>
#include <conio.h>
#include <graphics.h>

int sign(int x) {
    if (x < 0) return -1;
    else if (x > 0) return 1;
    else return 0;
}

void bline(int x1, int y1, int x2, int y2, int col) {
    int dx, dy, e, x, y, i = 1;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    e = 2 * dy - dx;
    while (i <= dx) {
        while (e >= 0) {
            y++;
            e = e - 2 * dx;
        }
        x++;
        e = e + 2 * dy;
        putpixel(x, y, col);
        i++;
    }
}

void ddaline(int x1, int y1, int x2, int y2, int col) {
    int x, y, len, i;
    float dx, dy;
    if (x1 == x2 && y1 == y2)
        putpixel(x1, y1, col);
    else {
        dx = x2 - x1;
        dy = y2 - y1;
        if (dx > dy)
            len = dx;
        else
            len = dy;
        dx = (x2 - x1) / len;
        dy = (y2 - y1) / len;
        x = x1 + 0.5 * sign(dx);
        y = y1 + 0.5 * sign(dy);
        i = 1;
        while (i < len) {
            putpixel(x, y, col);
            x = x + dx;
            y = y + dy;
            i++;
        }
    }
}

// Function to draw a circle using Bresenham's algorithm
void bcircle(int xc, int yc, int r, int col) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y) {
        putpixel(xc + x, yc + y, col);
        putpixel(xc - x, yc + y, col);
        putpixel(xc + x, yc - y, col);
        putpixel(xc - x, yc - y, col);
        putpixel(xc + y, yc + x, col);
        putpixel(xc - y, yc + x, col);
        putpixel(xc + y, yc - x, col);
        putpixel(xc - y, yc - x, col);
        
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else {
            d = d + 4 * x + 6;
        }
    }
}

int main() {
    int ch, col, x1, x2, y1, y2;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");

    ddaline(50, 50, 50, 200, 2); // left vertical line
    ddaline(50, 50, 350, 50, 4); // upper horizontal line
    ddaline(350, 50, 350, 200, 6); // right vertical line
    ddaline(50, 200, 350, 200, 7); // lower horizontal line

    ddaline(200, 50, 50, 125, 9); // diamond upper left line
    bline(50, 125, 200, 200, 12); // diamond left down line
    ddaline(350, 125, 200, 200, 14); // diamond down right line
    bline(200, 50, 350, 125, 3); // diamond right up line

    bcircle(200, 125, 66, 10); // Draw a circle inside the diamond

    getch();
    closegraph();
    return 0;
}
