#include "stdafx.h"
#include "EdgePolyFill.h"

#include <algorithm>
#include "algorithm"

EdgePolyFill::EdgePolyFill(CDC* pDC, COLORREF front_color, COLORREF back_color)
    : pDC(pDC), front_color(front_color), back_color(back_color)
{
    
}

COLORREF EdgePolyFill::get_neg_color(COLORREF color)
{
    return color == this->front_color ? back_color : front_color;
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
        double K = 1.0 * (p_min.x - p_max.x) / (p_min.y - p_max.y);
        
        for (int y = p_min.y; y <= p_max.y; y+=step)
        {
            for (int x = p_min.x; x <= x_end; x++)
                for (int k = 1; k <= step; k++)
                    this->pDC->SetPixel(
                        x,
                        y - k,
                        get_neg_color(this->pDC->GetPixel(x, y))
                    );

            p_min.x += K * step;
        }
    }
}
