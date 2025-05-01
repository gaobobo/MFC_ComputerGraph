/*
* 对于最新版本(2018及以上)，使用 #include "stdafx.h" 而非 #include "stdafx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 stdafx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "stdafx.h"
#include "CohenSu.h"
#include <strstream>


CohenSu::CohenSu(int wxl, int wxr, int wyb, int wyt, COLORREF boarder, COLORREF line, CDC* pDC)
    : window_x_left(wxl), window_x_right(wxr), window_y_bottom(wyb), window_y_top(wyt),
        boarder_color(boarder), line_color(line), pDC(pDC)
{
}

unsigned int CohenSu::EnCode(double x, double y)
{
    return (x < this->window_x_left) |
           (x > this->window_x_right) << 1 |
           (y > this->window_y_bottom) << 2 |
           (y < this->window_y_top) << 3;
}

void CohenSu::CohenSutherland(CPoint start, CPoint end)
{
    unsigned int code1 = this->EnCode(start.x, start.y);
    unsigned int code2 = this->EnCode(end.x, end.y);
    
    if (code1 & code2) return;
    
    if (!(code1 | code2))
    {
        CPen* pPen = new CPen(PS_SOLID, 1, this->line_color);
        this->pDC->SelectObject(pPen);
        this->pDC->MoveTo(start);
        this->pDC->LineTo(end);
        pPen->DeleteObject();
        return;
    }
    
    if (code1 == 0b0000)
    {
        std::swap(start, end);
        std::swap(code1, code2);
    }

    unsigned int center_point_code = this->EnCode(0.5 * (start.x + end.x), 0.5 * (start.y + end.y));
    
    const double K = 1.0 * (end.y - start.y) / (end.x - start.x);
    const double B = start.y - K * start.x;

    int intersection_x;
    int intersection_y;

    if (center_point_code & 0b0011)
    {
        intersection_x = (center_point_code & 0b0001) ? this->window_x_left : this->window_x_right;
        intersection_y = K * intersection_x + B;
    } else
    {
        intersection_y = (center_point_code & 0b0100) ? this->window_y_top : this->window_y_bottom;
        intersection_x = K * (intersection_y - B);
    }

    CPoint intersection_point = CPoint(intersection_x, intersection_y);
    this->CohenSutherland(intersection_point, end);
    
}

void CohenSu::OnDraw()
{
    CPen* pPen = new CPen(PS_SOLID, 1, this->boarder_color);
    this->pDC->SelectObject(pPen);
    this->pDC->Rectangle(this->window_x_left,
                        this->window_y_top,
                        this->window_x_right,
                        this->window_y_bottom);

    pPen->DeleteObject();
}
