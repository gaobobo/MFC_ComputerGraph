
// MFC-7_3DTransView.h: CMFC73DTransView 类的接口
//

#pragma once


class CMFC73DTransView : public CView
{
protected: // 仅从序列化创建
	CMFC73DTransView() noexcept;
	DECLARE_DYNCREATE(CMFC73DTransView)

// 特性
public:
	CMFC73DTransDoc* GetDocument() const;

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
	virtual ~CMFC73DTransView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-7_3DTransView.cpp 中的调试版本
inline CMFC73DTransDoc* CMFC73DTransView::GetDocument() const
   { return reinterpret_cast<CMFC73DTransDoc*>(m_pDocument); }
#endif

