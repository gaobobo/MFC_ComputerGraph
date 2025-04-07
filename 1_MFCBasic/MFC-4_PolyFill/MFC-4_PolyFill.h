
// MFC-4_PolyFill.h: MFC-4_PolyFill 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFC4PolyFillApp:
// 有关此类的实现，请参阅 MFC-4_PolyFill.cpp
//

class CMFC4PolyFillApp : public CWinApp
{
public:
	CMFC4PolyFillApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC4PolyFillApp theApp;
