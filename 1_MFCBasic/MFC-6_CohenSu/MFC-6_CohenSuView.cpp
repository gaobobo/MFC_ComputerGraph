
// MFC-6_CohenSuView.cpp: CMFC6CohenSuView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-6_CohenSu.h"
#endif

#include "MFC-6_CohenSuDoc.h"
#include "MFC-6_CohenSuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6CohenSuView

IMPLEMENT_DYNCREATE(CMFC6CohenSuView, CView)

BEGIN_MESSAGE_MAP(CMFC6CohenSuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC6CohenSuView 构造/析构

CMFC6CohenSuView::CMFC6CohenSuView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC6CohenSuView::~CMFC6CohenSuView()
{
}

BOOL CMFC6CohenSuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC6CohenSuView 绘图

void CMFC6CohenSuView::OnDraw(CDC* /*pDC*/)
{
	CMFC6CohenSuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC6CohenSuView 打印

BOOL CMFC6CohenSuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC6CohenSuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC6CohenSuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC6CohenSuView 诊断

#ifdef _DEBUG
void CMFC6CohenSuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6CohenSuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6CohenSuDoc* CMFC6CohenSuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6CohenSuDoc)));
	return (CMFC6CohenSuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6CohenSuView 消息处理程序
