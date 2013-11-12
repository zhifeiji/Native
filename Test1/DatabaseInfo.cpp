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

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDatabaseInfo::CDatabaseInfo()
{

}

CDatabaseInfo::~CDatabaseInfo()
{

}

int CDatabaseInfo::GetDatabases(vector<CString> &vecDB)
{
	vecDB.clear();
	vecDB.push_back("db_test");
	vecDB.push_back("db_scs");

	return ERROR_NO_ERROR;
}

int CDatabaseInfo::GetTables(const CString &strDB, vector<CString> &vecTbl)
{
	//
	vecTbl.clear();

	vecTbl.push_back("aa");
	vecTbl.push_back("tbl1");

	return ERROR_NO_ERROR;
}