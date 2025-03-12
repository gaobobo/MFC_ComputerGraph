#include "pch.h"
#include "Bresenham.h"

Bresenham::Bresenham(CDC* pDC)
{
    this->pDC = pDC;
}

Bresenham::~Bresenham()
{
    
}

void Bresenham::DrawLine(CPoint start, CPoint end, COLORREF color)
{
    const double K = end.x - start.x ? fabs((end.y - start.y) / (end.x - start.x)) : -1;

	if (0 <= K && K <= 1)
	{
		if (start.x > end.x)
		{
			// 交换两数
			start.x = start.x ^ end.x;
			end.x = start.x ^ end.x ^ end.x;
			start.x = start.x ^ end.x;
		}

		double e = -0.5;

		while (start.x - end.x)
		{
			e += K;
			start.Offset(1, e >= 0
				? pow(1, e -= 1)	// 当 e>= 0 时，y+1，误差 e-1
				: 0);
			this->pDC->SetPixel(start, color);
		}
		
	} else
	{
		if (start.y > end.y)
		{
			// 交换两数
			start.y = start.y ^ end.y;
			end.y = start.y ^ end.y;
			start.y = start.y ^ end.y;
		}
		
		double e = -0.5;

		while (start.x - end.x)
		{
			e += K < 0 ? 0 : K;
			start.Offset(e >= 0
				? pow(1, e -= 1)	// 当 e>= 0 时，x+1，误差 e-1
				: 0,
				1);
			this->pDC->SetPixel(start, color);
		}
	}

}
