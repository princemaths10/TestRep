#pragma once

class CImageProcessLog
{
public:
	CImageProcessLog(void);
	~CImageProcessLog(void);

public:

	int WriteLog(CString str);
	int WriteHalLog(UINT4 err,CString strMes);
	int SetPath(CString strPath);
private:
	CFile f;

	CString m_Path;

	CTime timeNow;
	CString strTime;
	CString strWrite;
};

