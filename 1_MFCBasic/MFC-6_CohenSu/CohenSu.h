#pragma once

class CohenSu
{
public:
    CohenSu(int wxl, int wxr, int wyb, int wyt, COLORREF boarder, COLORREF line, CDC* pDC);
    unsigned int EnCode(double x, double y);
    void CohenSutherland(CPoint start, CPoint end);
    void OnDraw();

private:
    int window_x_left;
    int window_x_right;
    int window_y_bottom;
    int window_y_top;

    COLORREF boarder_color;
    COLORREF line_color;

    CDC* pDC;
};
