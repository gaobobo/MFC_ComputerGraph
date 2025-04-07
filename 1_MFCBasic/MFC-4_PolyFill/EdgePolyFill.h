#pragma once

class EdgePolyFill
{
    
public:
    CDC* pDC;

    void Draw(CPoint* poly, int point_num, int step=1);
    
    EdgePolyFill(CDC* pDC, COLORREF front_color, COLORREF back_color);

private:
    COLORREF front_color;
    COLORREF back_color;
    
    void draw_negative_point(int x, int y);
};
