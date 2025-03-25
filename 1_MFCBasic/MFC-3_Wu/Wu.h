#pragma once

class Wu
{
public:
    CPoint start = CPoint(0, 0);
    CPoint end = CPoint(0, 0);
    CDC* pDC;

    Wu(CPoint start, CPoint end, CDC* pDC);
    void Draw(COLORREF color = RGB(0, 0, 0));
};
