
// MFC-6_CohenSuView.h: CMFC6CohenSuView 类的接口
//

#pragma once


class CMFC6CohenSuView : public CView
{
protected: // 仅从序列化创建
	CMFC6CohenSuView() noexcept;
	DECLARE_DYNCREATE(CMFC6CohenSuView)

// 特性
public:
	CMFC6CohenSuDoc* GetDocument() const;

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
	virtual ~CMFC6CohenSuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-6_CohenSuView.cpp 中的调试版本
inline CMFC6CohenSuDoc* CMFC6CohenSuView::GetDocument() const
   { return reinterpret_cast<CMFC6CohenSuDoc*>(m_pDocument); }
#endif

