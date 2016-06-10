
// calculatorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <string>
#include <vector>
using namespace std;

// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
//	CEdit m_Edit;
	CString m_Edit;
	CString m_EditText;
	vector<CString> TmpStack;
	vector<CString> FinalStack;
	vector<CString> Equation;
	bool m_IsLegal();
	void m_ClearText();
	bool m_DealNum();
	bool flag = 0;
	bool m_ToPostfix();
	double m_Result();
	double m_Calculate(double);
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonDoubledot();
	afx_msg void OnBnClickedButtonZroe();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButton15Multi();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnBnClickedButtonClear();
};
