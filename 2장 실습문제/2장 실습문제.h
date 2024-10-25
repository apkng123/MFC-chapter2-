
// 2장 실습문제.h: 2장 실습문제 애플리케이션의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMy2장실습문제App:
// 이 클래스의 구현에 대해서는 2장 실습문제.cpp을(를) 참조하세요.
//

class CMy2장실습문제App : public CWinAppEx
{
public:
	CMy2장실습문제App() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2장실습문제App theApp;
