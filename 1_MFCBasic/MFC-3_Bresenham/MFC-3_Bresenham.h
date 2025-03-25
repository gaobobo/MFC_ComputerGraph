
// MFC-3_Bresenham.h: MFC-3_Bresenham 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC3BresenhamApp:
// 有关此类的实现，请参阅 MFC-3_Bresenham.cpp
//

class CMFC3BresenhamApp : public CWinApp
{
public:
	CMFC3BresenhamApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC3BresenhamApp theApp;
