
// 2장 실습문제View.cpp: CMy2장실습문제View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "2장 실습문제.h"
#endif

#include "2장 실습문제Doc.h"
#include "2장 실습문제View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2장실습문제View

IMPLEMENT_DYNCREATE(CMy2장실습문제View, CView)

BEGIN_MESSAGE_MAP(CMy2장실습문제View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2장실습문제View 생성/소멸

CMy2장실습문제View::CMy2장실습문제View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy2장실습문제View::~CMy2장실습문제View()
{
}

BOOL CMy2장실습문제View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2장실습문제View 그리기

void CMy2장실습문제View::OnDraw(CDC* pDC)
{
	CMy2장실습문제Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDC -> DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	pDC->TextOut(10, 10, m_strWindowSize);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy2장실습문제View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2장실습문제View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2장실습문제View 진단

#ifdef _DEBUG
void CMy2장실습문제View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2장실습문제View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2장실습문제Doc* CMy2장실습문제View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2장실습문제Doc)));
	return (CMy2장실습문제Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2장실습문제View 메시지 처리기


void CMy2장실습문제View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_strWindowSize.Format(_T("윈도우의 크기는 넓이 %d, 높이 %d입니다."),cx,cy);
	Invalidate();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy2장실습문제View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2장실습문제View::OnLButtonDown(UINT nFlags, CPoint point)
{	
	m_bDrag = TRUE;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy2장실습문제View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("오른쪽 마우스 버튼을 눌렀습니다");
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMy2장실습문제View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutput = _T("키보드를 눌렀습니다.");
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy2장실습문제View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_bDrag)
	{
		m_strOutput = _T("마우스를 드래그하고 있습니다.");
	}
	else
	{
		m_strOutput = _T("마우스를 이동 중입니다.");

	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy2장실습문제View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}
