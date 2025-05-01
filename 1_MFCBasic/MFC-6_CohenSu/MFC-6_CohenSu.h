
// MFC-6_CohenSu.h: MFC-6_CohenSu 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC6CohenSuApp:
// 有关此类的实现，请参阅 MFC-6_CohenSu.cpp
//

class CMFC6CohenSuApp : public CWinApp
{
public:
	CMFC6CohenSuApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC6CohenSuApp theApp;
