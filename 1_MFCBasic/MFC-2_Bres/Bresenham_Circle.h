#pragma once

class Bresenham_Circle
{
public:
    Bresenham_Circle(CDC* pDC);

    void DrawLine(CPoint start, CPoint end, COLORREF color = RGB(0, 0, 0));

private:
    CDC* pDC;
};
