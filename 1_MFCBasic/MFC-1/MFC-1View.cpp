
// MFC-1View.cpp: CMFC1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-1.h"
#endif

#include "MFC-1Doc.h"
#include "MFC-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1View

IMPLEMENT_DYNCREATE(CMFC1View, CView)

BEGIN_MESSAGE_MAP(CMFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC1View 构造/析构

CMFC1View::CMFC1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC1View::~CMFC1View()
{
}

BOOL CMFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC1View 绘图

void CMFC1View::OnDraw(CDC* pDC)
{
	CMFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CPen blue_3_solid_pen(PS_SOLID, 3, RGB(0, 0, 255));

	CPen red_1_dot_pen(PS_DOT, 1, RGB(255, 0, 0));

	CPen green_2_solid_pen(PS_SOLID, 2, RGB(0, 255, 0));
	CBrush blue_cross_brush(HS_DIAGCROSS, RGB(0, 0, 255));
	

	// 线条
	pDC->SelectObject(&blue_3_solid_pen);
	pDC->MoveTo(10, 10);
	pDC->LineTo(100, 100);

	blue_3_solid_pen.DeleteObject();

	//矩形
	pDC->SelectObject(&red_1_dot_pen);
	pDC->Rectangle(120, 10, 230, 110);

	red_1_dot_pen.DeleteObject();

	// 圆
	pDC->SelectObject(&green_2_solid_pen);
	pDC->SelectObject(&blue_cross_brush);
	pDC->Ellipse(240, 10, 340, 110);

	green_2_solid_pen.DeleteObject();
	blue_cross_brush.DeleteObject();

}


// CMFC1View 打印

BOOL CMFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC1View 诊断

#ifdef _DEBUG
void CMFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1Doc* CMFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1Doc)));
	return (CMFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1View 消息处理程序
