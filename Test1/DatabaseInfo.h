// DatabaseInfo.h: interface for the CDatabaseInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_)
#define AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

#include "scsdbclient.h"

using namespace std;



class CDatabaseInfo  
{
public:
	
	virtual ~CDatabaseInfo();
	static CDatabaseInfo *GetInstance();


private:
	static CDatabaseInfo *m_pDatabaseInfo;
	SCSDB m_scsdbhd;

	CString m_strIP;
	CString m_strUser;
	CString m_strPasswd;
 	CString m_strDB;
	
	CDatabaseInfo();


public:
	int GetDatabases(vector<CString> &vecDB);
	int GetTables(const CString &strDB, vector<CString> &vecTbl);


	// 打开数据库连接
	int OpenScsdb(void);
	// 执行sql语句
	int ExecuteSql(CString strSql,vector<vector<CString> > &vecRes);
};

#endif // !defined(AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_)
