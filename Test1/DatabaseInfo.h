// DatabaseInfo.h: interface for the CDatabaseInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_)
#define AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

using namespace std;

class CDatabaseInfo  
{
public:
	CDatabaseInfo();
	virtual ~CDatabaseInfo();

public:
	int GetDatabases(vector<CString> &vecDB);
	int GetTables(const CString &strDB, vector<CString> &vecTbl);


};

#endif // !defined(AFX_DATABASEINFO_H__21679EB6_5A86_4CC3_9B18_1C175534436F__INCLUDED_)
