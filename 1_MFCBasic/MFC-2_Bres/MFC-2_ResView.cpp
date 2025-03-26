
// MFC-2_ResView.cpp: CMFC2ResView 类的实现
//

/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "StdAfx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 StdAfx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "StdAfx.h"
#include "Bresenham.h"

#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-2_Res.h"
#endif

#include "MFC-2_ResDoc.h"
#include "MFC-2_ResView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2ResView

IMPLEMENT_DYNCREATE(CMFC2ResView, CView)

BEGIN_MESSAGE_MAP(CMFC2ResView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC2ResView 构造/析构

CMFC2ResView::CMFC2ResView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC2ResView::~CMFC2ResView()
{
}

BOOL CMFC2ResView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2ResView 绘图

void CMFC2ResView::OnDraw(CDC* pDC)
{
	CMFC2ResDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	Bresenham(pDC).DrawLine(CPoint(100, 300), CPoint(100, 600));
	Bresenham(pDC).DrawLine(CPoint(100, 400), CPoint(100, 100));
	Bresenham(pDC).DrawLine(CPoint(300, 100), CPoint(500, 100));
	Bresenham(pDC).DrawLine(CPoint(400, 100), CPoint(100, 100));
	Bresenham(pDC).DrawLine(CPoint(200, 200), CPoint(400, 100));
	Bresenham(pDC).DrawLine(CPoint(200, 300), CPoint(100, 200));
}


// CMFC2ResView 打印

BOOL CMFC2ResView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC2ResView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC2ResView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC2ResView 诊断

#ifdef _DEBUG
void CMFC2ResView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2ResView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2ResDoc* CMFC2ResView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2ResDoc)));
	return (CMFC2ResDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2ResView 消息处理程序
