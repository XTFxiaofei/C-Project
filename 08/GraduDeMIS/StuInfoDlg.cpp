// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StuInfoDlg.h"
#include "TecrDclrSubDlg.h"
#include "ChoisubDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog


CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuInfoDlg)
	m_ChoiSubStatusVal = _T("");
	m_EnsuPswdVal = _T("");
	m_FormerPswdVal = _T("");
	m_NewPswdVal = _T("");
	//}}AFX_DATA_INIT
	flag=false;
}


void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Text(pDX, IDC_ChoiSubStatus_EDIT, m_ChoiSubStatusVal);
	DDX_Text(pDX, IDC_EnsuPswd_EDIT, m_EnsuPswdVal);
	DDX_Text(pDX, IDC_FormerPswd_EDIT, m_FormerPswdVal);
	DDX_Text(pDX, IDC_NewPswd_EDIT, m_NewPswdVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	ON_BN_CLICKED(IDC_EditPswd_BTN, OnEditPswdBTN)
	ON_BN_CLICKED(IDC_OkBTN, OnOkBTN)
	ON_BN_CLICKED(IDC_QueChoiedSub_BTN, OnQueChoiedSubBTN)
	ON_BN_CLICKED(IDC_CancelBTN, OnCancelBTN)
	ON_BN_CLICKED(IDC_ToChoiSub_BTN, OnToChoiSubBTN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

void CStuInfoDlg::OnEditPswdBTN() 
{
	// TODO: Add your control notification handler code here
	 CButton *btn1=(CButton *)GetDlgItem(IDC_STATIC1);
	btn1->ShowWindow(SW_SHOW);
	CButton *btn2=(CButton *)GetDlgItem(IDC_STATIC2);
	btn2->ShowWindow(SW_SHOW);
	CButton *btn3=(CButton *)GetDlgItem(IDC_STATIC3);
	btn3->ShowWindow(SW_SHOW);
	CButton *btn4=(CButton *)GetDlgItem(IDC_FormerPswd_EDIT);
	btn4->ShowWindow(SW_SHOW);
	CButton *btn5=(CButton *)GetDlgItem(IDC_NewPswd_EDIT);
	btn5->ShowWindow(SW_SHOW);
	CButton *btn6=(CButton *)GetDlgItem(IDC_EnsuPswd_EDIT);
	btn6->ShowWindow(SW_SHOW);
	CButton *btn7=(CButton *)GetDlgItem(IDC_OkBTN);
	btn7->ShowWindow(SW_SHOW);
	CButton *btn8=(CButton *)GetDlgItem(IDC_CancelBTN);
	btn8->ShowWindow(SW_SHOW);
	CButton *btn9=(CButton *)GetDlgItem(IDC_EditPswd_BTN);
	btn9->ShowWindow(SW_HIDE);
	CButton *btn10=(CButton *)GetDlgItem(IDC_ToChoiSub_BTN);
	btn10->ShowWindow(SW_HIDE);
	CButton *btn11=(CButton *)GetDlgItem(IDC_QueChoiedSub_BTN);
	btn11->ShowWindow(SW_HIDE);
	CButton *btn12=(CButton *)GetDlgItem(IDC_STATIC4);
	btn12->ShowWindow(SW_HIDE);
	CButton *btn13=(CButton *)GetDlgItem(IDC_ChoiSubStatus_EDIT);
	btn13->ShowWindow(SW_HIDE);
}

void CStuInfoDlg::OnOkBTN() 
{
	// TODO: Add your control notification handler code here
/*		CString strPswd;
//	CGraduDeMISApp *point=(CGraduDeMISApp *)AfxGetApp();
	UpdateData();
	pStuLgnSet.Open();
	pStuLgnSet.MoveFirst();
	while(!pStuLgnSet.IsEOF())
	{
		if(pStuLgnSet.m_stu_id==strExternUser)
		{
			strPswd=pStuLgnSet.m_stu_loginPassword;
			break;
		}
		else
			pStuLgnSet.MoveNext();

	}
	UpdateData();
	if(strPswd!=m_FormerPswdVal)
	   MessageBox("原始密码错误！请输入正确的密码","提示信息",MB_OK);
	else
	   if(m_NewPswdVal!=m_EnsuPswdVal)
		  MessageBox("新密码不一致，请确认！","提示信息",MB_OK);
	   else
	   {
		   MessageBox("更改密码成功！","提示信息",MB_OK);
		   pStuLgnSet.Edit();
		   pStuLgnSet.m_stu_loginPassword=m_NewPswdVal;
		   pStuLgnSet.Update();
	   }
	pStuLgnSet.Close();

    CDatabase db;
	CString str;
	CGraduDeMISApp *point=(CGraduDeMISApp *)AfxGetApp();
	CStuLoginSet dbStuLog(&db);
    dbStuLog.Open(CRecordset::forwardOnly,"select stu_loginPassword from tab_StuLogin where stu_id='point->strExternUser'");
	MessageBox(point->strExternUser);  
	dbStuLog.GetFieldValue("stu_loginPassword",str);*/

}

void CStuInfoDlg::OnQueChoiedSubBTN() 
{
	// TODO: Add your control notification handler code here
	CTecrDclrSubDlg dlg;
	dlg.DoModal();
}

void CStuInfoDlg::OnCancelBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
/*
void MyHide(char str)
{
	CButton *pBtn=(CButton *)GetDlgItem(str);
	pBtn->ShowWindow(SW_HIDE);
}*/
BOOL CStuInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
    CButton *btn1=(CButton *)GetDlgItem(IDC_STATIC1);
	btn1->ShowWindow(SW_HIDE);
	CButton *btn2=(CButton *)GetDlgItem(IDC_STATIC2);
	btn2->ShowWindow(SW_HIDE);
	CButton *btn3=(CButton *)GetDlgItem(IDC_STATIC3);
	btn3->ShowWindow(SW_HIDE);
	CButton *btn4=(CButton *)GetDlgItem(IDC_FormerPswd_EDIT);
	btn4->ShowWindow(SW_HIDE);
	CButton *btn5=(CButton *)GetDlgItem(IDC_NewPswd_EDIT);
	btn5->ShowWindow(SW_HIDE);
	CButton *btn6=(CButton *)GetDlgItem(IDC_EnsuPswd_EDIT);
	btn6->ShowWindow(SW_HIDE);
	CButton *btn7=(CButton *)GetDlgItem(IDC_OkBTN);
	btn7->ShowWindow(SW_HIDE);
	CButton *btn8=(CButton *)GetDlgItem(IDC_CancelBTN);
	btn8->ShowWindow(SW_HIDE);

//	CGraduDeMISApp *point=(CGraduDeMISApp *)AfxGetApp();
/*	pStuLgnSet.Open();
	pStuLgnSet.MoveFirst();
	while(!pStuLgnSet.IsEOF())
	{
		if(strExternUser==pStuLgnSet.m_stu_id)
		{
			flag=pStuLgnSet.m_stu_ChoiSubStatus;
			break;
		}
		else
			pStuLgnSet.MoveNext();
	}
	pStuLgnSet.Close();
	if(flag)
	{
		m_ChoiSubStatusVal="你已经选题！";
		CButton *btnChoiSub=(CButton *)GetDlgItem(IDC_ToChoiSub_BTN);
        btnChoiSub->ShowWindow(SW_HIDE);
	}
	else
	{
		m_ChoiSubStatusVal="你尚未选题！";
		CButton *btnQueChoiedSub=(CButton *)GetDlgItem(IDC_QueChoiedSub_BTN);
        btnQueChoiedSub->ShowWindow(SW_HIDE);
	}
	UpdateData(false);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStuInfoDlg::OnToChoiSubBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancelBTN();
	CChoisubDlg dlg;
	dlg.DoModal();
}
