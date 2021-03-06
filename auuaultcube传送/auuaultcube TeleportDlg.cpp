
// auuaultcube TeleportDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "auuaultcube Teleport.h"
#include "auuaultcube TeleportDlg.h"
#include "afxdialogex.h"

#include "windows.h"



DWORD Pid;
HANDLE hProcess;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CauuaultcubeTeleportDlg 对话框



CauuaultcubeTeleportDlg::CauuaultcubeTeleportDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUUAULTCUBETELEPORT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CauuaultcubeTeleportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, M_EDlT1);
	DDX_Control(pDX, IDC_EDIT2, M_EDIT2);
	DDX_Control(pDX, IDC_EDIT3, M_EDIT3);
}

BEGIN_MESSAGE_MAP(CauuaultcubeTeleportDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CauuaultcubeTeleportDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CauuaultcubeTeleportDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CauuaultcubeTeleportDlg 消息处理程序

BOOL CauuaultcubeTeleportDlg::OnInitDialog()
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

void CauuaultcubeTeleportDlg::OnPaint()
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
HCURSOR CauuaultcubeTeleportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int Api_ReadMemoryInt(ULONG64 游戏进程, int a)
{
	HANDLE hProcess;
	DWORD t;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, 游戏进程);
	ReadProcessMemory(hProcess, (LPCVOID)(a), &t, 4, NULL);
	CloseHandle(hProcess);
	return t;
}

float 写小数型(ULONG64 游戏进程, int a, int b)
{
	HANDLE hProcess;
	float t = b;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, 游戏进程);
	WriteProcessMemory(hProcess, (LPVOID)(a), &t, 4, NULL);
	CloseHandle(hProcess);
	return t;
}

void Api_WriteMemoryInt(ULONG64 游戏进程, int a, int b)
{
	HANDLE hProcess;
	int t = b;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, 游戏进程);
	WriteProcessMemory(hProcess, (LPVOID)(a), &t, sizeof(t), NULL);
	CloseHandle(hProcess);
}

void CauuaultcubeTeleportDlg::OnBnClickedButton1()
{
	GetWindowThreadProcessId(::FindWindowA("SDL_app", "AssaultCube"), &Pid);
	if (Pid == 0)
	{
		MessageBox("请打开游戏OR获取游戏失败！");
	}
	DWORD x, y, z;
	int dataAddress;
	DWORD Baseaddress;
	Baseaddress = Api_ReadMemoryInt(Pid, 0x509B74);
	x = Api_ReadMemoryInt(Pid, Baseaddress + 0x38);
	y = Api_ReadMemoryInt(Pid, Baseaddress + 0x3c);
	z = Api_ReadMemoryInt(Pid, Baseaddress + 0x40);
	SetDlgItemInt(IDC_EDIT1, x);
	SetDlgItemInt(IDC_EDIT2, y);
	SetDlgItemInt(IDC_EDIT3, z);
	//UpdataDate(TURE);


}


void CauuaultcubeTeleportDlg::OnBnClickedButton2()
{
	GetWindowThreadProcessId(::FindWindowA("SDL_app", "AssaultCube"), &Pid);
	if (Pid == 0)
	{
		MessageBox("请打开游戏OR获取游戏失败！");
	}
	int dataAddress;
	DWORD Baseaddress;
	int num, num2, num3;
	CString str1, str2,str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str3);
	Baseaddress = Api_ReadMemoryInt(Pid, 0x509B74);
	num = atoi(str1);
	num2 = atoi(str2);
	num3 = atoi(str3);
	Api_WriteMemoryInt(Pid, Baseaddress + 0x38, num);
	Api_WriteMemoryInt(Pid, Baseaddress + 0x3c, num2);
	Api_WriteMemoryInt(Pid, Baseaddress + 0x40, num3);
	// TODO: 在此添加控件通知处理程序代码
}
