#pragma once

class Bresenham
{
public:
    Bresenham(CDC* pDC);
    ~Bresenham();
    void DrawLine(CPoint start, CPoint end, COLORREF color = RGB(0, 0, 0));

private:
    CDC* pDC;
};
