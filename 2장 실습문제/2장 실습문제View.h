
// 2장 실습문제View.h: CMy2장실습문제View 클래스의 인터페이스
//

#pragma once


class CMy2장실습문제View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy2장실습문제View() noexcept;
	DECLARE_DYNCREATE(CMy2장실습문제View)

// 특성입니다.
public:
	CMy2장실습문제Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy2장실습문제View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strWindowSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CString m_strOutput;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	bool m_bDrag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2장 실습문제View.cpp의 디버그 버전
inline CMy2장실습문제Doc* CMy2장실습문제View::GetDocument() const
   { return reinterpret_cast<CMy2장실습문제Doc*>(m_pDocument); }
#endif

