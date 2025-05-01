/*
* 对于最新版本(2018及以上)，使用 #include "stdafx.h" 而非 #include "stdafx.h"
 * 或通过“解决方案管理器 -> 右键项目 -> 属性-> C/C++ -> 预编译头”中查看预编译头
 * 名称。如果你是从Gitee/Github下载的该项目，那么该名称已经修改为 stdafx.h 。
 * 预编译头可以加快编译速度，原因是不常更新的只编译一次，因此没有考虑移除预编译头。
 */
// #include "pch.h"
#include "stdafx.h"
#include "CohenSu.h"

// MFC-6_CohenSuView.cpp: CMFC6CohenSuView 类的实现
//

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

void CMFC6CohenSuView::OnDraw(CDC* pDC)
{
	CMFC6CohenSuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	auto drawer = CohenSu(250, 850, 450, 250, RGB(0, 0, 0), RGB(255, 0, 0), pDC);
	drawer.OnDraw();

	drawer.CohenSutherland(CPoint(260, 260), CPoint(750, 350));
	drawer.CohenSutherland(CPoint(200, 200), CPoint(100, 500));
	drawer.CohenSutherland(CPoint(100, 100), CPoint(600, 350));
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
