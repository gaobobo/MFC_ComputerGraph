/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "stdafx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 stdafx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "stdafx.h"


// MFC-5_SeedFillView.cpp: CMFC5SeedFillView 类的实现
//

#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-5_SeedFill.h"
#endif

#include "MFC-5_SeedFillDoc.h"
#include "MFC-5_SeedFillView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5SeedFillView

IMPLEMENT_DYNCREATE(CMFC5SeedFillView, CView)

BEGIN_MESSAGE_MAP(CMFC5SeedFillView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC5SeedFillView 构造/析构

CMFC5SeedFillView::CMFC5SeedFillView() noexcept
{
	// TODO: 在此处添加构造代码

	Head = Last = NULL;
}

CMFC5SeedFillView::~CMFC5SeedFillView()
{
}

BOOL CMFC5SeedFillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC5SeedFillView 绘图

void CMFC5SeedFillView::OnDraw(CDC* pDC)
{
	CMFC5SeedFillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CPoint p[] = {
		CPoint(550, 400),
		CPoint(350, 600),
		CPoint(250, 350),
		CPoint(350, 50),
		CPoint(500, 250),
		CPoint(600, 50),
		CPoint(800, 450),
		CPoint(550, 400)
	};
	
	this->PolygonFill(pDC, p, 8, CPoint(500, 300), RGB(0, 0, 0), RGB(255, 0, 0));
}


// CMFC5SeedFillView 打印

BOOL CMFC5SeedFillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC5SeedFillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC5SeedFillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

// SeedFill 实现

void CMFC5SeedFillView::Push(CPoint point)
{
	Base = new Stack_node;
	Base->PixelPoint = point;
	Base->Next = NULL;

	if (Head == NULL)
	{
		Last = Head = Base;	
	} else
	{
		Last->Next = Base;
		Last = Base;
	}
	
}

Stack_node* CMFC5SeedFillView::Pop()
{
	Stack_node *t;
	Base = Head;

	if (Base->Next == NULL)
	{
		Head = NULL;
		return Base;
	}

	while (Base->Next != NULL)
	{
		Base = Base->Next;

		if (Base->Next == Last)
		{
			Base->Next = NULL;
			t = Last;
			Last = Base;
			return t;
		}
	}

	return NULL;
}

void CMFC5SeedFillView::PolygonFill(CDC* pDC, CPoint* p, int n, CPoint seed, COLORREF ec, COLORREF fc)
{
	CPen pen(PS_SOLID, 1, ec);
	pDC->SelectObject(&pen);
	
	for (int i = 1; i < n; i++)
	{
		pDC->MoveTo(p[i - 1].x, p[i - 1].y);
		pDC->LineTo(p[i].x, p[i].y);
	}

	pen.DeleteObject();

	this->Push(seed);

	Stack_node* element;
	while ((element = this->Pop()) != NULL)
	{
		CPoint point = element->PixelPoint;

		pDC->SetPixel(point, fc);

		CPoint neighbor_points[] = {
			CPoint(point.x, point.y + 1),
			CPoint(point.x, point.y - 1),
			CPoint(point.x + 1, point.y),
			CPoint(point.x - 1, point.y),
		};

		for each (CPoint i in neighbor_points)
		{
			if (pDC->GetPixel(i) != ec && pDC->GetPixel(i) != fc)
				this->Push(i);
		}
	}
}


// CMFC5SeedFillView 诊断

#ifdef _DEBUG
void CMFC5SeedFillView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5SeedFillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5SeedFillDoc* CMFC5SeedFillView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5SeedFillDoc)));
	return (CMFC5SeedFillDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5SeedFillView 消息处理程序
