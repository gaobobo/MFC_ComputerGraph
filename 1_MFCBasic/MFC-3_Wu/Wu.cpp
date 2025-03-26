/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "Wu.h"

Wu::Wu(CPoint start, CPoint end, CDC* pDC): start(start), end(end), pDC(pDC)
{
    
}

void Wu::Draw(COLORREF color)
{
    const int dx = end.x - start.x;
    const int dy = end.y - start.y;

    if (dx == 0 || abs(dy / dx) > 1)
    {
        if (start.y > end.y)
        {
            // 交换两数
            start.y = start.y ^ end.y;
            end.y = start.y ^ end.y;
            start.y = start.y ^ end.y;
        }
        
        int x = start.x;
        int y = start.y;
        double K = end.x - start.x ? 1.0 * dy / dx : 0;
        double e = fabs(K);
        
        while (y <= end.y)
        {
            y++;
            const int x_offset = K < 0 ? -1 : 1;
            
            if (e >= 1)
            {
                
                x += x_offset;
                e += fabs(K) - 1;

                pDC->SetPixelV(x , y, RGB((2 - e) * 255, (2 - e) * 255, (2 - e) * 255));
                pDC->SetPixelV(x + x_offset, y, RGB((e - 1) * 255,(e - 1) * 255,(e - 1) * 255));
            } else
            {
                e += fabs(K);

                pDC->SetPixelV(x, y, RGB(e * 255,e * 255,e * 255));
                pDC->SetPixelV(x + x_offset, y, RGB((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
            }
        }
    } else
    {
        if (start.x > end.x)
        {
            // 交换两数
            start.x = start.x ^ end.x;
            end.x = start.x ^ end.x;
            start.x = start.x ^ end.x;
        }
        
        int x = start.x;
        int y = start.y;
        const double K =  1.0 * dy / dx;
        double e = K;

        while (x <= end.x)
        {
            x++;
            const int y_offset = K < 0 ? -1 : 1;
    
            if (e >= 1)
            {
                
                y += y_offset;
                e += fabs(K) - 1;

                pDC->SetPixelV(x, y, RGB((2 - e) * 255, (2 - e) * 255, (2 - e) * 255));
                pDC->SetPixelV(x, y + y_offset, RGB((e - 1) * 255,(e - 1) * 255,(e - 1) * 255));
            } else
            {
                e += fabs(K);

                pDC->SetPixelV(x, y, RGB(e * 255,e * 255,e * 255));
                pDC->SetPixelV(x, y + y_offset, RGB((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
            }
        }   
    }
}
