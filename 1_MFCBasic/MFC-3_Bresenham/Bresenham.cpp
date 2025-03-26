/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "Bresenham.h"

Bresenham::Bresenham(CPoint center, int r, CDC* pDC) : y(r), d(1.25 - r), center(center), pDC(pDC)
{
}

void Bresenham::Draw(COLORREF color)
{
    int offset_x = center.x - r;
    int offset_y = center.y + r;
    while (x < y)
    {
        pDC->SetPixel(x + offset_x, y + offset_y, color);
        pDC->SetPixel(y + offset_x, x + offset_y, color);
        pDC->SetPixel(-y + offset_x, x + offset_y, color);
        pDC->SetPixel(x + offset_x, -y + offset_y, color);
        pDC->SetPixel(-x + offset_x, -y + offset_y, color);
        pDC->SetPixel(-y + offset_x, -x + offset_y, color);
        pDC->SetPixel(y + offset_x, -x + offset_y, color);
        pDC->SetPixel(-x + offset_x, y + offset_y, color);
    
        x++;
        y = d < 0 ? y : y - 1;
        
        d = d < 0 ? (d + 2 * x + 3) : d + 2 * (x - y) + 5;
    }
}
