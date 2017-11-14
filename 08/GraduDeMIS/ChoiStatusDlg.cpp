// ChoiStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "ChoiStatusDlg.h"
#include "TecrDclrSubDlg.h"
#include "ChoisubDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoiStatusDlg dialog


CChoiStatusDlg::CChoiStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChoiStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoiStatusDlg)
	m_strChoiSubStatus = _T("");
	//}}AFX_DATA_INIT
}


void CChoiStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoiStatusDlg)
	DDX_Text(pDX, IDC_STATIC_ChoiStatus, m_strChoiSubStatus);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoiStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CChoiStatusDlg)
	ON_BN_CLICKED(IDC_SeeChoisubInfo_BTN, OnSeeChoisubInfoBTN)
	ON_BN_CLICKED(IDC_EnterChoiSub_BTN, OnEnterChoiSubBTN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoiStatusDlg message handlers

//学生选题情况
BOOL CChoiStatusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here

	bool choisubStatus;														
	choisubSet.Open();//打开选题记录集
	while(!choisubSet.IsEOF())						//遍历记录集
	{
		if(choisubSet.m_stu_name==strExternUser)	//查找学生
		{
			//if(choisubSet.m_stu_choisubStatus)
			choisubStatus=true;						//选题状态
			break;
		}
		else
			choisubSet.MoveNext();					//移动到下调记录
	}
	choisubSet.Close();								//关闭记录集
	if(choisubStatus==true)							//判断是否选题
	{
        m_strChoiSubStatus="你已经选题！";
		CButton *pBtn1=(CButton *)GetDlgItem(IDC_EnterChoiSub_BTN);//获取控件指针
		pBtn1->ShowWindow(SW_HIDE);					//隐藏按钮
	}
	else
	{
        m_strChoiSubStatus="你尚未选题！";			
		CButton *pBtn2=(CButton *)GetDlgItem(IDC_SeeChoisubInfo_BTN);//获取控件指针
		pBtn2->ShowWindow(SW_HIDE);					//隐藏按钮
	}
    UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChoiStatusDlg::OnSeeChoisubInfoBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
	CTecrDclrSubDlg dlg;
	dlg.DoModal();						//打开查看选题信息对话框
}

void CChoiStatusDlg::OnEnterChoiSubBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
	CChoisubDlg dlg;
	dlg.DoModal();						//打开选题对话框
}

