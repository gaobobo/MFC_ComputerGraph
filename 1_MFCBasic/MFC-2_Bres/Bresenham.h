#pragma once

class Bresenham
{
public:
    Bresenham(CDC* pDC, int step = 1);
    ~Bresenham();
    void DrawLine(CPoint start, CPoint end, COLORREF color = RGB(0, 0, 0));

private:
    CDC* pDC;
    int step;
};
