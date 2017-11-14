// TeacherTab2.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TeacherTab2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab2 dialog


CTeacherTab2::CTeacherTab2(CWnd* pParent /*=NULL*/)
	: CDialog(CTeacherTab2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTeacherTab2)
	m_tecr_age = _T("");
	m_tecr_level = _T("");
	m_tecr_name = _T("");
	m_tecr_sex = _T("");
	m_tecr_TRroom = _T("");
	m_tecr_ascio = _T("");
	//}}AFX_DATA_INIT
}


void CTeacherTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeacherTab2)
	DDX_Text(pDX, IDC_TECR_AGE, m_tecr_age);
	DDX_Text(pDX, IDC_TECR_LEVEL, m_tecr_level);
	DDX_Text(pDX, IDC_TECR_NAME, m_tecr_name);
	DDX_Text(pDX, IDC_TECR_SEX, m_tecr_sex);
	DDX_Text(pDX, IDC_TECR_TRROOM, m_tecr_TRroom);
	DDX_Text(pDX, IDC_TECR_Ascio, m_tecr_ascio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeacherTab2, CDialog)
	//{{AFX_MSG_MAP(CTeacherTab2)
	ON_BN_CLICKED(IDC_TECR_ADD, OnTecrAdd)
	ON_BN_CLICKED(IDC_TECR_DEL, OnTecrDel)
	ON_BN_CLICKED(IDC_TECR_EDIT, OnTecrEdit)
	ON_BN_CLICKED(IDC_TECR_SAVE, OnTecrSave)
	ON_BN_CLICKED(IDC_TECR_CANCEL, OnTecrCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab2 message handlers

void CTeacherTab2::OnTecrAdd() 
{
	// TODO: Add your control notification handler code here
	
}

void CTeacherTab2::OnTecrEdit() 
{
	// TODO: Add your control notification handler code here
	
}

void CTeacherTab2::OnTecrDel() 
{
	// TODO: Add your control notification handler code here
	
}

void CTeacherTab2::OnTecrSave() 
{
	// TODO: Add your control notification handler code here
	
}

void CTeacherTab2::OnTecrCancel() 
{
	// TODO: Add your control notification handler code here
	
}

void CTeacherTab2::MyShow()
{
	
	if(!tecrSet.IsOpen())
	tecrSet.Open();
	while(!tecrSet.IsEOF())
	{
		if(tecrSet.m_tecr_name==selectID)
		{
			m_tecr_age=tecrSet.m_tecr_age;
			m_tecr_level=tecrSet.m_tecr_level;
			m_tecr_name=tecrSet.m_tecr_name;
			m_tecr_sex=tecrSet.m_tecr_sex;
			m_tecr_TRroom=tecrSet.m_tecr_TRroom;   
			m_tecr_ascio=tecrSet.m_tecr_asoci;
			break;
		}
		else
			tecrSet.MoveNext();
	}
	tecrSet.Close();
	UpdateData(FALSE);
}

BOOL CTeacherTab2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!tecrSet.IsOpen())						//打开记录集
		tecrSet.Open();		
	tecrSet.MoveFirst();						//移动到首条记录
	m_tecr_age=tecrSet.m_tecr_age;				//变量的赋值
	m_tecr_level=tecrSet.m_tecr_level;
	m_tecr_name=tecrSet.m_tecr_name;
	m_tecr_sex=tecrSet.m_tecr_sex;
	m_tecr_TRroom=tecrSet.m_tecr_TRroom;   
	m_tecr_ascio=tecrSet.m_tecr_asoci;	
	tecrSet.Close();							//关闭记录集
	UpdateData(FALSE);							//更新数据

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
