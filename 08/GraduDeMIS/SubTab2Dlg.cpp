// SubTab2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubTab2Dlg.h"
#include "TeacherSet.h"
#include "SubjectSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubTab2Dlg dialog


CSubTab2Dlg::CSubTab2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubTab2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubTab2Dlg)
	m_demand = _T("");
	m_name = _T("");
	m_pro = _T("");
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void CSubTab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubTab2Dlg)
	DDX_Control(pDX, IDC_SUB_TEA, m_combo);
	DDX_Text(pDX, IDC_SUB_DEMAND, m_demand);
	DDX_Text(pDX, IDC_SUB_NAME, m_name);
	DDX_Text(pDX, IDC_SUB_PRO, m_pro);
	DDX_Text(pDX, IDC_SUB_TYPE, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubTab2Dlg, CDialog)
	//{{AFX_MSG_MAP(CSubTab2Dlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubTab2Dlg message handlers
void CSubTab2Dlg::MyShow()
{
/*	if(!pSet2.IsOpen())
	pSet2.Open();
	while(!pSet2.IsEOF())
	{
		if(pSet2.m_stu_id==selectID)
		{
			m_StuTab2_ID=pSet2.m_stu_id;
			m_StuTab2_NAME=pSet2.m_stu_name;
			m_strSex=pSet2.m_stu_sex;
//			m_StuTab2_AGE=pSet2.m_stu_age;
//			m_StuTab2_DEPART=pSet2.m_stu_depart;    
			m_strClass=pSet2.m_stu_class;
			break;
		}
		else
			pSet2.MoveNext();
	}
	pSet2.Close();
	UpdateData(FALSE);*/
}

BOOL CSubTab2Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CDatabase *pDb = new CDatabase();
	CTeacherSet *pSet = new CTeacherSet(pDb);
	CString sql;
	sql = "select * from tab_tecr";
	pSet->Open(AFX_DB_USE_DEFAULT_TYPE, sql);
	while(!pSet->IsEOF())
	{
		m_combo.AddString(pSet->m_tecr_asoci);
		pSet->MoveNext();
	}
	m_combo.SetCurSel(0);
	pSet->Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubTab2Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CDatabase *pDb = new CDatabase;
	CSubjectSet *pSet = new CSubjectSet(pDb);
	pSet->Open();
	if(m_name == "")
	{
		MessageBox("请输入名称");
		return ;
	}
	CString sql, name;
	int nIndex = m_combo.GetCurSel();
	m_combo.GetLBText(nIndex, name);
	sql.Format("insert into tab_sub values ('%s', '%s', '%s', '%s', '%s')", m_name, m_type, m_pro, m_demand, name);
	try
	{
		pDb->ExecuteSQL(sql);
		MessageBox("添加成功！");
	}
	catch(...)
	{
		MessageBox("error!");
	}
	pSet->Requery();
	pSet->Close();
}

