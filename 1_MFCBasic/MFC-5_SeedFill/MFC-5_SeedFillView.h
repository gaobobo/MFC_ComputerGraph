// MFC-5_SeedFillView.h: CMFC5SeedFillView 类的接口
//

#pragma once
#include "Stack_node.h"


class CMFC5SeedFillView : public CView
{
protected: // 仅从序列化创建
	CMFC5SeedFillView() noexcept;
	DECLARE_DYNCREATE(CMFC5SeedFillView)

// 特性
public:
	CMFC5SeedFillDoc* GetDocument() const;

// 操作
public:
	Stack_node *Head, *Base, *Last;
	
	/**
	* 区域填充
	* @param pDC 
	* @param p 顶点数组
	* @param n 顶点个数
	* @param seed 种子点
	* @param ec 边界色
	* @param fc 填充色
	*/
	void PolygonFill(CDC *pDC, CPoint *p, int n, CPoint seed, COLORREF ec, COLORREF fc);

	/**
	 * 入栈
	 */
	void Push(CPoint point);

	/**
	 * 出栈
	 */
	Stack_node *Pop();


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC5SeedFillView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-5_SeedFillView.cpp 中的调试版本
inline CMFC5SeedFillDoc* CMFC5SeedFillView::GetDocument() const
   { return reinterpret_cast<CMFC5SeedFillDoc*>(m_pDocument); }
#endif

