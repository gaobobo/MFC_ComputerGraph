
// MFC-2_ResView.h: CMFC2ResView 类的接口
//

#pragma once


class CMFC2ResView : public CView
{
protected: // 仅从序列化创建
	CMFC2ResView() noexcept;
	DECLARE_DYNCREATE(CMFC2ResView)

// 特性
public:
	CMFC2ResDoc* GetDocument() const;

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
	virtual ~CMFC2ResView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC-2_ResView.cpp 中的调试版本
inline CMFC2ResDoc* CMFC2ResView::GetDocument() const
   { return reinterpret_cast<CMFC2ResDoc*>(m_pDocument); }
#endif

