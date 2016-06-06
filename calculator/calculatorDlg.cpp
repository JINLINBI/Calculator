
// calculatorDlg.cpp : ʵ���ļ�
//

//#include<iostream>
#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "Translate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalculatorDlg �Ի���



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_EditText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//DDX_Control(pDX, IDC_EDIT, m_Edit);
	DDX_Text(pDX, IDC_EDIT, m_EditText);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CcalculatorDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CcalculatorDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CcalculatorDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CcalculatorDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CcalculatorDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CcalculatorDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CcalculatorDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CcalculatorDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CcalculatorDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CcalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_DOUBLEDOT, &CcalculatorDlg::OnBnClickedButtonDoubledot)
	ON_BN_CLICKED(IDC_BUTTON_ZROE, &CcalculatorDlg::OnBnClickedButtonZroe)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON15_MULTI, &CcalculatorDlg::OnBnClickedButton15Multi)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CcalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CcalculatorDlg::OnBnClickedButtonResult)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CcalculatorDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CcalculatorDlg::OnBnClickedButtonRight)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CcalculatorDlg::m_ClearText()
{
	m_Edit = "";
}

bool CcalculatorDlg::m_DealNum()
{
	
	if (m_Edit.GetLength()>0) {
		//UpdateData(true);
		Equation.push_back(m_Edit);
		m_Edit = "";
		//UpdateData(false);
	}
	
	return true;
}

bool CcalculatorDlg::m_ToPostfix()
{
	CString tmp;
	reverse(Equation.begin(), Equation.end());
	while(!Equation.empty()) {
		tmp=Equation.back();
		Equation.pop_back();
		
		if (tmp == '+' || tmp == '-') {
			while (!TmpStack.empty() && TmpStack.back() != '(') {
				FinalStack.push_back(TmpStack.back());
				TmpStack.pop_back();
			}
			TmpStack.push_back(tmp);
		}
		else if (tmp == '*' || tmp == '/') {
			while (!TmpStack.empty() && (TmpStack.back() =='*' || TmpStack.back()=='/')) {	//
				FinalStack.push_back(TmpStack.back());
				TmpStack.pop_back();
			}
			TmpStack.push_back(tmp);
		}
		else if (tmp == '(') {
			TmpStack.push_back(tmp);
		}
		else if (tmp == ')') {
			CString out = TmpStack.back();
			TmpStack.pop_back();
			while (!TmpStack.empty() && out!='(') {
				FinalStack.push_back(out);
				out = TmpStack.back();
				TmpStack.pop_back();
			}	
		}
		else {
			FinalStack.push_back(tmp);
		}
	}

	while(!TmpStack.empty()) {
		FinalStack.push_back(TmpStack.back());
		TmpStack.pop_back();
	}
	return true;
}

double CcalculatorDlg::m_Result()
{
	CString tmp ;
	double numX,numY;
	double result;
	reverse(FinalStack.begin(), FinalStack.end());
	while (!FinalStack.empty()) {
		tmp= FinalStack.back();
		FinalStack.pop_back();
		if (tmp[0] <= '9' && tmp[0] >= '0') {
			Equation.push_back(tmp);
		}
		else {
			CString tmpX = Equation.back();
			numY = atof(tmpX);
			Equation.pop_back();
			CString tmpY = Equation.back();
			numX = atof(tmpY);
			Equation.pop_back();
			switch (tmp[0]) {
			case '+':result = numX + numY; break;
			case '-':result = numX - numY; break;
			case '*':result = numX * numY; break;
			case '/':result = numX / numY; break;
			}
			tmp.Format("%f",result);
			Equation.push_back(tmp);
		}
	}
	
	tmp=Equation.back();
	numX = atof(tmp);
	return numX;
}


void CcalculatorDlg::OnBnClickedButtonOne()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '1';
	m_Edit += '1';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonTwo()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '2';
	m_Edit += '2';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonThree()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '3';
	m_Edit += '3';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonFour()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '4';
	m_Edit += '4';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonFive()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '5';
	m_Edit += '5';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonSix()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '6';
	m_Edit += '6';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonSeven()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '7';
	m_Edit += '7';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonEight()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '8';
	m_Edit += '8';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonNine()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '9';
	m_Edit += '9';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonDot()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '.';
	m_Edit += '.';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonDoubledot()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '0';
	m_EditText += '0'; 
	m_Edit += '0';
	m_Edit += '0';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonZroe()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '0';
	m_Edit += '0';
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonPlus()
{
	UpdateData(true);
	m_EditText += '+';
	m_DealNum();
	CString tmp = "+";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	m_EditText += '-';
	m_DealNum();
	CString tmp = "-";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButton15Multi()
{
	m_EditText += '*';
	m_DealNum();
	CString tmp = "*";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonDivide()
{
	m_EditText += '/';
	m_DealNum();
	CString tmp = "/";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonResult()
{
	double num;
	m_DealNum();
	m_ToPostfix();
	num=m_Result();
	m_EditText.Format("%f",num);
	UpdateData(false);
	flag = true;
}


void CcalculatorDlg::OnBnClickedButtonLeft()
{
	m_EditText += '(';
	m_DealNum();
	CString tmp = "(";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonRight()
{
	m_EditText += ')';
	m_DealNum();
	CString tmp = ")";
	Equation.push_back(tmp);
	UpdateData(false);
}
