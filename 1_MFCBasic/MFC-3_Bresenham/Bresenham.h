#pragma once

class Bresenham
{
public:
    Bresenham(CPoint center, int r, CDC* pDC);
    
    void Draw(COLORREF color = RGB(0, 0, 0));

private:
    int x;
    int y;
    int r;
    CPoint center;
    double d;
    CDC* pDC;
};
