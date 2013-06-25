#include "StdAfx.h"
#include "EnumFileInfo.h"
//#include "tree.h"


CEnumFileInfo::CEnumFileInfo()
	: m_pFiles( 0 )
	, m_dwAllocated( 0 )
	, m_dwLen( 0 )
{
}

CEnumFileInfo::~CEnumFileInfo()
{
	if( m_pFiles )
	{
		free( m_pFiles );
	}
}

bool CEnumFileInfo::GetList(TCHAR* dir)
{
	WIN32_FIND_DATA data;
	TCHAR* findPath = (TCHAR*)malloc(wcslen(dir)*sizeof(TCHAR)+2);
	wcscpy(findPath, dir);
	if(dir[wcslen(dir)-1]!=L'\\')
	{
		dir = (TCHAR*)realloc(dir, wcslen(dir)+1);
		wcscat(dir, L"\\");
		wcscat(findPath, L"\\*");
	}
	else
		wcscat(findPath, L"*");

	wcscpy(data.cFileName,dir);
	
	
	Add(&data);
	HANDLE hFindFile = FindFirstFile(findPath, &data);
	if(hFindFile == NULL)
	{
		free(findPath);
		return 0;
	}
	do
	{
		if(wcscmp(data.cFileName,L".")==0 || wcscmp(data.cFileName,L"..")==0  || (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) continue;
		Add(&data);
	}while(FindNextFile(hFindFile, &data));
	FindClose(hFindFile);
	hFindFile = FindFirstFile(findPath, &data);
	if(hFindFile == NULL)
	{
		free(findPath);
		return 0;
	}
	do
	{
		if(wcscmp(data.cFileName,L".")==0 || wcscmp(data.cFileName,L"..")==0 || (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) continue;
		Add(&data);
	}while(FindNextFile(hFindFile, &data));
	FindClose(hFindFile);
	free(findPath);
	return true;
}


void CEnumFileInfo::Add( WIN32_FIND_DATA *item )
{
	if( m_dwLen <= m_dwAllocated )
	{
		m_dwAllocated = m_dwAllocated + 16;
		m_pFiles = (WIN32_FIND_DATA*)realloc( m_pFiles, m_dwAllocated * sizeof(WIN32_FIND_DATA) );
	}

	CopyMemory( m_pFiles + m_dwLen, item, sizeof(*item) );
	m_dwLen++;
}
