#pragma once

class Bresenham
{
public:
    int x = 0;
    int y = 0;
    int r = 0;
    CPoint center = CPoint(0, 0);
    double d = 1.25;
    CDC* pDC;

    Bresenham(CPoint center, int r, CDC* pDC);
    
    void Draw(COLORREF color = RGB(0, 0, 0));
};
