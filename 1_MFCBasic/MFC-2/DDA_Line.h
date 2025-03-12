#pragma once
class DDA_Line
{
public:
	CDC* pDC;

	DDA_Line(CDC* pDC);
	~DDA_Line();
	void DrawLine(CPoint start, CPoint end, COLORREF color = RGB(0, 0, 0));
};

