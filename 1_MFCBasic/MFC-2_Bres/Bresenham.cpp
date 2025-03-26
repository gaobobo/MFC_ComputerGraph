/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "Bresenham.h"

Bresenham::Bresenham(CDC* pDC): pDC(pDC)
{

}

Bresenham::~Bresenham()
{
    
}

void Bresenham::DrawLine(CPoint start, CPoint end, COLORREF color)
{
	const double K = end.x - start.x ? 1.0 * (end.y - start.y) / (end.x - start.x) : NAN;

	if (!isnan(K) && fabs(K) <= 1)
	{
		if (start.x > end.x)
		{
			// 交换两数
			start.x = start.x ^ end.x;
			end.x = start.x ^ end.x;
			start.x = start.x ^ end.x;
		}

		double e = -0.5;

		while (start.x - end.x <= 0)
		{
			e += fabs(K);
			start.Offset(1,
					 e >= 0
							? [&e, K]() {e--; return K < 0 ? -1 : 1;}()	// 当 e>=0 时， e-1 。如有 K<0，则偏移-1，否则反之。
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

		while (start.y - end.y <= 0)
		{
			e += isnan(K) ? 0 : fabs(K);
			start.Offset(e >= 0
							? [&e, K]() {e--; return K < 0 ? -1 : 1;}()	// 当 e<=0 时，如有 K<0，则偏移-1且 e-1，否则反之。
							: 0,
				1);
			this->pDC->SetPixel(start, color);
		}
	}

}
