
// MFC-3_BresenhamView.h: CMFC3BresenhamView 类的接口
//

#pragma once


class CMFC3BresenhamView : public CView
{
protected: // 仅从序列化创建
	CMFC3BresenhamView() noexcept;
	DECLARE_DYNCREATE(CMFC3BresenhamView)

// 特性
public:
	CMFC3BresenhamDoc* GetDocument() const;

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
	virtual ~CMFC3BresenhamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-3_BresenhamView.cpp 中的调试版本
inline CMFC3BresenhamDoc* CMFC3BresenhamView::GetDocument() const
   { return reinterpret_cast<CMFC3BresenhamDoc*>(m_pDocument); }
#endif

