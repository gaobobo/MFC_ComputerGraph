
// MFC-7_3DTransView.cpp: CMFC73DTransView 类的实现
//

#include "stdafx.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-7_3DTrans.h"
#endif

#include "MFC-7_3DTransDoc.h"
#include "MFC-7_3DTransView.h"
#include "3DPolyDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC73DTransView

IMPLEMENT_DYNCREATE(CMFC73DTransView, CView)

BEGIN_MESSAGE_MAP(CMFC73DTransView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC73DTransView 构造/析构

CMFC73DTransView::CMFC73DTransView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC73DTransView::~CMFC73DTransView()
{
}

BOOL CMFC73DTransView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC73DTransView 绘图

void CMFC73DTransView::OnDraw(CDC* pDC)
{
	CMFC73DTransDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	PolyDraw3D().OnDraw(pDC);
}


// CMFC73DTransView 打印

BOOL CMFC73DTransView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC73DTransView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC73DTransView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC73DTransView 诊断

#ifdef _DEBUG
void CMFC73DTransView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC73DTransView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC73DTransDoc* CMFC73DTransView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC73DTransDoc)));
	return (CMFC73DTransDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC73DTransView 消息处理程序
