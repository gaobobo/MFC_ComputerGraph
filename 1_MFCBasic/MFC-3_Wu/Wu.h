#pragma once

class Wu
{
public:
    Wu(CPoint start, CPoint end, CDC* pDC);

    void Draw(COLORREF color = RGB(0, 0, 0));

private:
    CPoint start;
    CPoint end;
    CDC* pDC;
};
