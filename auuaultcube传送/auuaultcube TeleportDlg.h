﻿
// auuaultcube TeleportDlg.h: 头文件
//

#pragma once


// CauuaultcubeTeleportDlg 对话框
class CauuaultcubeTeleportDlg : public CDialogEx
{
// 构造
public:
	CauuaultcubeTeleportDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUUAULTCUBETELEPORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit M_EDlT1;
	CEdit M_EDIT2;
	CEdit M_EDIT3;
	afx_msg void OnBnClickedButton2();
};
