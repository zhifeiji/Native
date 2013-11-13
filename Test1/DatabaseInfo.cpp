// DatabaseInfo.cpp: implementation of the CDatabaseInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test1.h"
#include "DatabaseInfo.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define ROW_MAX_SIZE (1024*1024)

// #pragma comment(lib, "scsdb.lib")
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CDatabaseInfo *CDatabaseInfo::m_pDatabaseInfo=NULL;

CDatabaseInfo::CDatabaseInfo()
{
	m_scsdbhd = NULL;
	m_strIP = "192.168.0.163";
	m_strUser = "SCS";
	m_strPasswd = "123456";
	m_strDB = "";
}

CDatabaseInfo::~CDatabaseInfo()
{

}

CDatabaseInfo *CDatabaseInfo::GetInstance()
{
	if (m_pDatabaseInfo == NULL)
	{
		m_pDatabaseInfo = new CDatabaseInfo();
	}
	return m_pDatabaseInfo;
}

int CDatabaseInfo::GetDatabases(vector<CString> &vecDB)
{
	vecDB.clear();

	CString strSql = "show databases";
	int ret;
	ret = ExecuteSql(strSql);
	if (ret == ERROR_NO_ERROR)
	{
		long long lolRowNum = scsdb_NumRow(m_scsdbhd);
		long long lColNum = scsdb_columnNum(m_scsdbhd);
		long long lAffectNum = scsdb_affected_rows(m_scsdbhd);
		//打印属性列表
		// 		for (int colidx = 0; colidx < lColNum; colidx++)
		// 		{
		// 			printf("  %s\t",scsdb_getcolumn(m_scsdbhd,colidx));
		// 		}
		// 		printf("\n");
		// 
		//打印查询结果
		for (long long rowidx = 0; rowidx < lolRowNum; rowidx++)
		{
			scsdb_ReadRow(m_scsdbhd);
			// 			printf("[%d] ",rowidx + 1);
// 			for(int colidx = 0; colidx < lColNum; colidx++)
// 			{
// 				printf("%s ",scsdb_Files(m_scsdbhd,colidx));
// 			}
			vecDB.push_back(scsdb_Files(m_scsdbhd,0));


// 			printf("\n");
		}

// 		printf("affect rows = %ld\n",lAffectNum);
		scsdb_release(m_scsdbhd);
	}
	return ret;
}

int CDatabaseInfo::GetTables(const CString &strDB, vector<CString> &vecTbl)
{
	//
	vecTbl.clear();

	CString strSql1;
	strSql1.Format("use %s",strDB);

	CString strSql2 = "show tables";

	int ret;
	ret = ExecuteSql(strSql1);
	if (ret != ERROR_NO_ERROR)
	{
		return ret;
	}
	ret = ExecuteSql(strSql2);
	if (ret == ERROR_NO_ERROR)
	{
		long long lolRowNum = scsdb_NumRow(m_scsdbhd);
		long long lColNum = scsdb_columnNum(m_scsdbhd);
		long long lAffectNum = scsdb_affected_rows(m_scsdbhd);
		//打印属性列表
		// 		for (int colidx = 0; colidx < lColNum; colidx++)
		// 		{
		// 			printf("  %s\t",scsdb_getcolumn(m_scsdbhd,colidx));
		// 		}
		// 		printf("\n");
		// 
		//打印查询结果
		for (long long rowidx = 0; rowidx < lolRowNum; rowidx++)
		{
			scsdb_ReadRow(m_scsdbhd);
			// 			printf("[%d] ",rowidx + 1);
			// 			for(int colidx = 0; colidx < lColNum; colidx++)
			// 			{
			// 				printf("%s ",scsdb_Files(m_scsdbhd,colidx));
			// 			}
			vecTbl.push_back(scsdb_Files(m_scsdbhd,0));


			// 			printf("\n");
		}

		// 		printf("affect rows = %ld\n",lAffectNum);
		scsdb_release(m_scsdbhd);

	}
	return ret;
}
// 打开数据库连接
int CDatabaseInfo::OpenScsdb(void)
{
	if(NULL == (m_scsdbhd = scsdb_open((LPSTR)(LPCTSTR)m_strIP,(LPSTR)(LPCTSTR)m_strUser,(LPSTR)(LPCTSTR)m_strPasswd,(LPSTR)(LPCTSTR)m_strDB)))
	{
		AfxMessageBox("scsdb_open failed!");
		//printf("[%d] scsdb_open failed!\n");
		return ERROR_OPEN_SCSDB; 
	}
	return ERROR_NO_ERROR;
}

// 执行sql语句
int CDatabaseInfo::ExecuteSql(CString strSql)
{
	if (scsdb_executesql(m_scsdbhd, (LPSTR)(LPCTSTR)strSql))
	{
		CString strErr;
		strErr.Format("execute sql [%s] fail!errno = %d, errmsg = %s",strSql,scsdb_geterror(m_scsdbhd), scsdb_geterror_string(m_scsdbhd));
		AfxMessageBox(strErr);
		return ERROR_EXECUTE_SQL;
	}
	return ERROR_NO_ERROR;
}
