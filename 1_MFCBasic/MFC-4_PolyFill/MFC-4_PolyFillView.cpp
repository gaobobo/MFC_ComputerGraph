
// MFC-4_PolyFillView.cpp: CMFC4PolyFillView 类的实现
//

#include "stdafx.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-4_PolyFill.h"
#endif

#include "MFC-4_PolyFillDoc.h"
#include "MFC-4_PolyFillView.h"

#include "EdgePolyFill.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4PolyFillView

IMPLEMENT_DYNCREATE(CMFC4PolyFillView, CView)

BEGIN_MESSAGE_MAP(CMFC4PolyFillView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC4PolyFillView 构造/析构

CMFC4PolyFillView::CMFC4PolyFillView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4PolyFillView::~CMFC4PolyFillView()
{
}

BOOL CMFC4PolyFillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4PolyFillView 绘图

void CMFC4PolyFillView::OnDraw(CDC* pDC)
{
	CMFC4PolyFillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CPoint ploy_points[] = {CPoint(550, 400),
							CPoint(350, 600),
							CPoint(250, 350),
							CPoint(350, 50),
							CPoint(500, 250),
							CPoint(600, 50),
							CPoint(800, 450),
							CPoint(550, 400)};
	EdgePolyFill(pDC, RGB(0, 0, 0), RGB(255, 255, 255)).Draw(ploy_points, 8, 6);
}


// CMFC4PolyFillView 打印

BOOL CMFC4PolyFillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC4PolyFillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC4PolyFillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC4PolyFillView 诊断

#ifdef _DEBUG
void CMFC4PolyFillView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4PolyFillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4PolyFillDoc* CMFC4PolyFillView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4PolyFillDoc)));
	return (CMFC4PolyFillDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4PolyFillView 消息处理程序
