/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "DDA_Line.h"

DDA_Line::DDA_Line(CDC* pDC, int step): step(step), pDC(pDC)
{

}

DDA_Line::~DDA_Line()
{
	
}

void DDA_Line::DrawLine(CPoint start, CPoint end, COLORREF color)
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
		auto next_point = [this](CPoint* p, double k)
			{ p->Offset(this->step, round(k)); return *p; };
		while (start.x - end.x <= 0) this->pDC->SetPixel(next_point(&start, K), color);		
	} else
	{
		if (start.y > end.y)
		{
			// 交换两数
			start.y = start.y ^ end.y;
			end.y = start.y ^ end.y;
			start.y = start.y ^ end.y;
		}
		auto next_point = [this](CPoint* p, double k)
			{ p->Offset(round(k) * this->step, 1); return *p;};
		while (start.y - end.y <= 0) this->pDC->SetPixel(next_point(&start, isnan(K) ? 0 : K), color);
	}
}
