
// MFC-3_WuView.cpp: CMFC3WuView 类的实现
//
/*
* 对于最新版本(2018及以上)，使用 #include "pch.h" 而非 #include "stdafx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 stdafx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "stdafx.h"
#include "Wu.h"

#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-3_Wu.h"
#endif

#include "MFC-3_WuDoc.h"
#include "MFC-3_WuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3WuView

IMPLEMENT_DYNCREATE(CMFC3WuView, CView)

BEGIN_MESSAGE_MAP(CMFC3WuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC3WuView 构造/析构

CMFC3WuView::CMFC3WuView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3WuView::~CMFC3WuView()
{
}

BOOL CMFC3WuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3WuView 绘图

void CMFC3WuView::OnDraw(CDC* pDC)
{
	CMFC3WuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	Wu(CPoint(100, 100), CPoint(500, 300), pDC).Draw();

	// Wu(CPoint(100, 300), CPoint(100, 600), pDC).Draw();
	// Wu(CPoint(100, 400), CPoint(100, 100), pDC).Draw();
	// Wu(CPoint(300, 100), CPoint(500, 100), pDC).Draw();
	// Wu(CPoint(400, 100), CPoint(100, 100), pDC).Draw();
	// Wu(CPoint(200, 200), CPoint(400, 100), pDC).Draw();
	// Wu(CPoint(200, 300), CPoint(100, 200), pDC).Draw();
	
}


// CMFC3WuView 打印

BOOL CMFC3WuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC3WuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC3WuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC3WuView 诊断

#ifdef _DEBUG
void CMFC3WuView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3WuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3WuDoc* CMFC3WuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3WuDoc)));
	return (CMFC3WuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3WuView 消息处理程序
