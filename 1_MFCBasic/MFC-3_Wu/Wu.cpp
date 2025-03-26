#include "pch.h"
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
