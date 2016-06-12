
// calculatorDlg.cpp : 实现文件
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


// CcalculatorDlg 对话框



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
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CcalculatorDlg::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalculatorDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


bool CcalculatorDlg::m_IsLegal()
{
	bool isLegal = true;
	CString insertStr="*";
	char last='\0',now;
	bool flag = true;
	int countofMark = 0;
	m_DealNum();
	if (!Equation.empty()) {
		for (vector<CString>::iterator it = Equation.begin(); it !=Equation.end(); it++) {
			
			if (*it[0] == '(') {
				countofMark += 1;
			}
			else if (*it[0] == ')') {
				countofMark -= 1;
			}
			{
				now = *it[0];

				if (last == ')'&& now == '(') {	//如果是两个括号之间的话,添加一个*号
					it = Equation.insert(it, insertStr);//将iterator指向*
						countofMark--;//撤销刚才对 "("符号的计数
				}
				if (')' == last && now >= 48 && now <= 57) {//添加括号
					it = Equation.insert(it, insertStr);
				}
				if ('(' == now && last >= 48 && last <= 57) {//添加括号
					it = Equation.insert(it, insertStr);
						countofMark--;//撤销刚才对 "("符号的计数
				}
				if ('(' == last && (now== '+' || now== '-' || now == '*' || now == '/')) {	//如果出现了(*+/-的情况是不合法的
					flag = false;
				}
				if (')' == now && (last == '+' || last== '-' || last == '*' || last == '/')) {//如果出现了*+/-的情况是不合法的
					flag = false;
				}
				last = now;
			}
			
		}
		if (countofMark != 0 || !flag) {
			isLegal = false;
		}
	}
	return isLegal;
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
	TmpStack.clear();
	if(!Equation.empty())
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
	TmpStack.clear();
	if(!FinalStack.empty())
	reverse(FinalStack.begin(), FinalStack.end());
	while (!FinalStack.empty()) {
		tmp= FinalStack.back();
		FinalStack.pop_back();
		if (tmp[0] <= '9' && tmp[0] >= '0') {
			TmpStack.push_back(tmp);
		}
		else {
			CString tmpX = TmpStack.back();
			numY = atof(tmpX);
			TmpStack.pop_back();
			CString tmpY = TmpStack.back();
			numX = atof(tmpY);
			TmpStack.pop_back();
			switch (tmp[0]) {
			case '+':result = numX + numY; break;
			case '-':result = numX - numY; break;
			case '*':result = numX * numY; break;
			case '/':result = numX / numY; break;
			}
			tmp.Format("%f",result);
			TmpStack.push_back(tmp);
		}
	}
	if (!TmpStack.empty()) {
		tmp = TmpStack.back();
		Equation.push_back(tmp);
	}
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
	if (m_Edit.Find('.')>=0) {
		return;
	}
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
	char tmpChar = '0';
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	else {
		tmpChar = m_EditText.GetAt(m_EditText.GetLength() - 1);
	}
	if (tmpChar <= 47 && tmpChar >= 42) {//如果是两个+-*/的符号,那么不合法
		m_EditText.Delete(m_EditText.GetLength() - 1, 1);
		m_EditText += '+';
		Equation.pop_back();
		Equation.push_back("+");
		UpdateData(false);
	}
	else {
		m_EditText += '+';
		m_DealNum();
		CString tmp = "+";
		Equation.push_back(tmp);
		UpdateData(false);
	}
	
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	UpdateData(true);
	char tmpChar = '0';
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	else {
		tmpChar = m_EditText.GetAt(m_EditText.GetLength() - 1);
	}
	if (tmpChar <= 47 && tmpChar >= 42) {//如果是两个+-*/的符号,那么不合法
		m_EditText.Delete(m_EditText.GetLength() - 1, 1);
		Equation.pop_back();
		m_EditText += '-';
		Equation.push_back("-");
		UpdateData(false);
	}
	else {
		m_EditText += '-';
		m_DealNum();
		CString tmp = "-";
		Equation.push_back(tmp);
		UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedButton15Multi()
{
	UpdateData(true);
	char tmpChar='0';
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	else {
		tmpChar=m_EditText.GetAt(m_EditText.GetLength() - 1);
	}
	if (tmpChar <= 47 && tmpChar >= 42) {//如果是两个+-*/的符号,那么不合法
		m_EditText.Delete(m_EditText.GetLength() - 1, 1);
		Equation.pop_back();
		m_EditText += '*';
		Equation.push_back("*");
		UpdateData(false);
	}
	else {
		m_EditText += '*';
		m_DealNum();
		CString tmp = "*";
		Equation.push_back(tmp);
		UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedButtonDivide()
{
	UpdateData(true);
	char tmpChar = '0';
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	else {
		tmpChar = m_EditText.GetAt(m_EditText.GetLength() - 1);
	}
	if (tmpChar <= 47 && tmpChar >= 42) {//如果是两个+-*/的符号,那么不合法
		m_EditText.Delete(m_EditText.GetLength() - 1, 1);
		Equation.pop_back();
		Equation.push_back("/");
		m_EditText += '/';
		UpdateData(false);
	}
	else {
		m_EditText += '/';
		m_DealNum();
		CString tmp = "/";
		Equation.push_back(tmp);
		UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedButtonResult()
{
	double num;
	CString tail;
	if (m_IsLegal()==false) {
		MessageBox("错误,请重新输入!", "消息:", MB_OK| MB_ICONERROR);
		return;
	}
	else {
		if (flag) {
			m_EditText = "";
			flag = false;
		}
		m_DealNum();
		m_ToPostfix();//转换为后缀表达式
		num = m_Result();//计算得到结果


		tail.Format("=%f", num);
		m_EditText += tail;
		UpdateData(false);
		flag = true;
	}
	
	
}


void CcalculatorDlg::OnBnClickedButtonLeft()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += '(';
	m_DealNum();
	CString tmp = "(";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonRight()
{
	if (flag) {
		m_EditText = "";
		flag = false;
	}
	m_EditText += ')';
	m_DealNum();
	CString tmp = ")";
	Equation.push_back(tmp);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedButtonCancel()
{
	
	CString tmpStr;
	if (m_EditText.Find('=') >= 0) {
		m_EditText = "";
		m_Edit = "";
	}
	int num = m_EditText.GetLength();
	int length = m_Edit.GetLength();
	char tmp;
	if (num > 0) {//如果有东西在输入框的话
		tmp= m_EditText.GetAt(num-1);
		m_EditText.Delete(num - 1, 1);
		if (tmp<='9'&& tmp>='0') {//如果删掉的是数字,那么不用出栈数据
			if(length>0)
			m_Edit.Delete(length - 1, 1);	//字符串减掉最后一个就好
			else {
				if (!Equation.empty())	//出栈数据
				{
					tmpStr = Equation.back();
					tmpStr.Delete(tmpStr.GetLength() - 1, 1);
					Equation.pop_back();
					if (!tmpStr)
						Equation.push_back(tmpStr);
				}
					
			}
			//UpdateData(false);
		}
		else {		
			if(!Equation.empty())			//出栈数据
			Equation.pop_back();
		}
		
	}
	
	UpdateData(false);
}




void CcalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_EditText = "";
	m_Edit = "";
	TmpStack.clear();
	Equation.clear();
	UpdateData(false);
}
