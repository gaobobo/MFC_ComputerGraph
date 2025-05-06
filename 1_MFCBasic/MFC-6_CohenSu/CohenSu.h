#pragma once

class CohenSu
{
public:
    CohenSu(int wxl, int wxr, int wyb, int wyt, COLORREF window_boarder_colorref, COLORREF line_colorref, CDC* pDC);
    unsigned int EnCode(double x, double y);
    void CohenSutherland(CPoint start, CPoint end);
    void OnDraw();

private:
    int window_x_left;
    int window_x_right;
    int window_y_bottom;
    int window_y_top;

    COLORREF window_color;
    COLORREF line_color;

    CDC* pDC;
};
