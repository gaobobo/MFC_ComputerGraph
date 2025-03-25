#include "pch.h"
#include "Bresenham.h"

Bresenham::Bresenham(CPoint center, int r, CDC* pDC) : x(0) ,y(r), d(1.25 - r), center(center), pDC(pDC)
{
}

void Bresenham::Draw(COLORREF color)
{
    int offset_x = center.x - r;
    int offset_y = center.y + r;
    while (x < y)
    {
        pDC->SetPixel(x + offset_x, y + offset_y, color);
        pDC->SetPixel(y + offset_x, x + offset_y, color);
        pDC->SetPixel(-y + offset_x, x + offset_y, color);
        pDC->SetPixel(x + offset_x, -y + offset_y, color);
        pDC->SetPixel(-x + offset_x, -y + offset_y, color);
        pDC->SetPixel(-y + offset_x, -x + offset_y, color);
        pDC->SetPixel(y + offset_x, -x + offset_y, color);
        pDC->SetPixel(-x + offset_x, y + offset_y, color);
    
        x++;
        y = d < 0 ? y : y - 1;
        
        d = d < 0 ? (d + 2 * x + 3) : d + 2 * (x - y) + 5;
    }
}
