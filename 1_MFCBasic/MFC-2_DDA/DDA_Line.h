#pragma once
class DDA_Line
{
public:
	DDA_Line(CDC* pDC, int step = 1);
	~DDA_Line();
	void DrawLine(CPoint start, CPoint end, COLORREF color = RGB(0, 0, 0));

private:
	CDC* pDC;
	int step;
};

