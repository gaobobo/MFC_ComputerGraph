/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "DDA_Line.h"

#include <cmath>

DDA_Line::DDA_Line(CDC* pDC, int step): step(step), pDC(pDC)
{

}

void DDA_Line::DrawLine(CPoint start, CPoint end, COLORREF color)
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
		const double K = dx ? 1.0 * dy / dx : 0;
		const int x_offset = (K > 0) - (K < 0);	// K > 0, 1; K == 0, 0; K < 0, -1;
        
		while (y <= end.y)
		{
			this->pDC->SetPixel(x += x_offset * this->step, y++, color);
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
		const double K = 1.0 * dy / dx;
		const int y_offset = (K > 0) - (K < 0);	// K > 0, 1; K == 0, 0; K < 0, -1;
		

		while (x <= end.x)
		{
			this->pDC->SetPixel(x += this->step, y += y_offset, color);
		}
	}
}
