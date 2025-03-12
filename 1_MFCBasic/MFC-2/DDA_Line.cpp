#include "pch.h"
#include "DDA_Line.h"

DDA_Line::DDA_Line(CDC* pDC)
{
	this->pDC = pDC;
}

DDA_Line::~DDA_Line()
{
	
}

void DDA_Line::DrawLine(CPoint start, CPoint end, COLORREF color)
{
	const double K = end.x - start.x ? fabs((end.y - start.y) / (end.x - start.x)) : -1;

	if (0 <= K && K <= 1)
	{
		if (start.x > end.x)
		{
			start.x = start.x ^ end.x;
			end.x = start.x ^ end.x ^ end.x;
			start.x = start.x ^ end.x;
		}
		auto next_point = [](CPoint* p, int k) {p->Offset(1, k); return *p;};
		while (start.x - end.x) this->pDC->SetPixel(next_point(&start, K), color);		
	} else
	{
		if (start.y > end.y)
		{
			start.y = start.y ^ end.y;
			end.y = start.y ^ end.y;
			start.y = start.y ^ end.y;
		}
		auto next_point = [](CPoint* p, int k) {p->Offset(k < 0 ? 0 : k, 1); return *p;};
		while (start.y - end.y) this->pDC->SetPixel(next_point(&start, K), color);
	}
}
