
// TestView.h : CTestView ��Ľӿ�
//

#pragma once

#include "Face.h"
#include "Vector.h"
#include "ZBuffer.h"
#include "Lighting.h"
#include "Transform.h"
class CTestView : public CView
{
protected: // �������л�����
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// ����
public:
	CTestDoc* GetDocument() const;

// ����
public:
	void ReadVertex();//���붥���
	void ReadFace();//�������
	void InitParameter();//�任����
	void PerProject(CP3);//͸��ͶӰ
	void DoubleBuffer(CDC *pDC);//˫����
	void DrawObject(CDC *);//��������	

// ��д
public:
	void Diamond();//���ƽ��ʯͼ������
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	double R,Theta,Phi;//�ӵ����û�����ϵ�е�������
	double d;//�Ӿ�
	double Near,Far;//Զ��������
	double k[9];//͸�ӱ任����
	CP3 ViewPoint;//�ӵ�������λ��
	CPi3 ScreenP;//��Ļ����ϵ����ά�����
	double Alpha,Beta;//x������ת����,y������ת�½�
	CP3 *V;//��Ķ���һά����
	CFace **F;//��Ķ�ά����
	int N1,N2;//N1Ϊγ������,N2Ϊ��������
	int LightNum;//��Դ����
	CLighting *pLight;//���ջ���
	CMaterial *pMaterial;//�������
	BOOL bPlay;//��������
	CTransform tran;//�任����
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnDrawpic();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnInitialUpdate();
	afx_msg void OnPlay();
	afx_msg void OnUpdatePlay(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // TestView.cpp �еĵ��԰汾
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

