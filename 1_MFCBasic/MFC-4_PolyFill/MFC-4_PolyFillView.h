
// MFC-4_PolyFillView.h: CMFC4PolyFillView 类的接口
//

#pragma once


class CMFC4PolyFillView : public CView
{
protected: // 仅从序列化创建
	CMFC4PolyFillView() noexcept;
	DECLARE_DYNCREATE(CMFC4PolyFillView)

// 特性
public:
	CMFC4PolyFillDoc* GetDocument() const;

// 操作
public:

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
	virtual ~CMFC4PolyFillView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-4_PolyFillView.cpp 中的调试版本
inline CMFC4PolyFillDoc* CMFC4PolyFillView::GetDocument() const
   { return reinterpret_cast<CMFC4PolyFillDoc*>(m_pDocument); }
#endif

