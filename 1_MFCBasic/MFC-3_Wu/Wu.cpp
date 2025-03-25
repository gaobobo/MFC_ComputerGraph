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
            pDC->SetPixelV(x, y,RGB(e*255,e*255,e*255));
            pDC->SetPixelV(x,y+1,RGB((1-e)*255,(1-e)*255,(1-e)*255));
            
            y++;
            
            if (e >= 1)
            {
                x += K < 0 ? -1 : 1;
                e += fabs(K) - 1;
            } else
            {
                e += fabs(K);
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
            pDC->SetPixelV(x, y, RGB(e * 255,e * 255,e * 255));
            pDC->SetPixelV(x, y + 1, RGB((1 - e) * 255, (1 - e) * 255, (1 - e) * 255));
        
            x++;
    
            if (e >= 1)
            {
                y += K < 0 ? -1 : 1;
                e += fabs(K) - 1;
            } else
            {
                e += fabs(K);
            }
        }   
    }
}
