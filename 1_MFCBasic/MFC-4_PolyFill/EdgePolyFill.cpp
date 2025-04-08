/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "stdafx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 stdafx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "stdafx.h"
#include "EdgePolyFill.h"
#include <algorithm>

EdgePolyFill::EdgePolyFill(CDC* pDC, COLORREF front_color, COLORREF back_color)
    : pDC(pDC), front_color(front_color), back_color(back_color)
{
    
}

void EdgePolyFill::draw_negative_point(int x, int y)
{
    COLORREF color = this->pDC->GetPixel(x, y) == front_color ? back_color : front_color;
    this->pDC->SetPixel(x, y, color);
}

void EdgePolyFill::Draw(CPoint* poly, int point_num, int step)
{
    int x_end = poly[0].x;
    for (int i = 0; i < point_num; i++)
    {
        x_end = std::max<INT>(poly[i].x, x_end);
    }

    for (int i = 1; i < point_num; i++)
    {
        CPoint p_max = poly[i].y > poly[i - 1].y ? poly[i] : poly[i - 1];
        CPoint p_min =  poly[i].y < poly[i - 1].y ? poly[i] : poly[i - 1];
        const double m = p_min.y != p_max.y ? 1.0 * (p_min.x - p_max.x) / (p_min.y - p_max.y) : 0;
        double x_actual = p_min.x;
        
        for (int y = p_min.y; y < p_max.y; y++)
        {
            for (int x = p_min.x; x <= x_end; x++)
                draw_negative_point(x, y);

            // 防止误差过大，写时转int，而非每次累加直接转换为int。
            x_actual += y % step == 0 ? m * step : 0;
            p_min.x = static_cast<int>(x_actual);
        }
    }
}
