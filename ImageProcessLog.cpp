#include "StdAfx.h"
#include "ImageProcessLog.h"

CImageProcessLog::CImageProcessLog(void)
{
	m_Path = "";
	// Get Path
	char filename[MAX_PATH] = {0};
	::GetModuleFileName(NULL,filename,MAX_PATH);        
	int len = strlen(filename);
	for(int i=len;i>=0;i--)
	{
		if(filename[i] == '\\')
		{
			filename[i] = '\0';	
			break;
		}
		filename[i] = '\0';
	}
	m_Path.Format("%s", filename);
}

CImageProcessLog::~CImageProcessLog(void)
{

}

int CImageProcessLog::WriteLog(CString str)
{
	try
	{	
		timeNow = CTime::GetCurrentTime();
		strTime =  timeNow.Format("%Y-%m-%d %H:%M:%S");  

		strWrite = strTime + "," + str + "\r\n";

		char fileName[MAX_PATH];
		char *pDestr;
		pDestr =strWrite.GetBuffer(strWrite.GetLength());

		if(!f.Open( _T(m_Path+"\\"+"ProcessLog.txt"), CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite)) 
		{
			return -2;
		}   

		f.SeekToEnd();

		f.Write(pDestr,strWrite.GetLength());

		f.Flush();
		f.Close();

	}
	catch (CException* e)
	{
		return -1;
	}

	return 0;
}

int CImageProcessLog::WriteHalLog(UINT4 err,CString strMes)
{
	//Hal
	if (err == 2 )
	{
		return 0;
	}

	try
	{	
		CString str;
		timeNow = CTime::GetCurrentTime();
		strTime =  timeNow.Format("%Y-%m-%d %H:%M:%S");  

		str.Format("Halcon Error:%u",err);
		strWrite = strTime + "," + str+"," + strMes + "\r\n";

		char fileName[MAX_PATH];
		char *pDestr;
		pDestr =strWrite.GetBuffer(strWrite.GetLength());

		if(!f.Open( _T(m_Path+"\\"+"ProcessLog.txt"), CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite)) 
		{
			return -2;
		}   

		f.SeekToEnd();

		f.Write(pDestr,strWrite.GetLength());

		f.Flush();
		f.Close();

	}
	catch (CException* e)
	{
		return -1;
	}

	return 0;

}

int CImageProcessLog::SetPath(CString strPath)
{
	m_Path = strPath;
	return 0;
}