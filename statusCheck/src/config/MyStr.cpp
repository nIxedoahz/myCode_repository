/*=========================================================
*	File name	��	MyStr.cpp
*	Authored by	��	
*	Date		��	
*	Description	��	
*
*	Modify  	��	
*=========================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "config/MyStr.h"


/***********************************************************
 * ������: ~CStr()
 * ��������: ��������
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:56 
***********************************************************/ 
CStr::~CStr()
{
#ifdef DEBUG_TEST
	printf("CStr:%p, strData:%p in ~CStr(), CStr destructure\n", this, strData);
#endif

	if (NULL == strData)
		return;
	else
	{
		free(strData);
		strData = NULL;
		strLength = 0;
	}

	return;
}

void CStr::FreeData()
{
	if (NULL == strData)
		return;
	else
	{
		free(strData);
		strData = NULL;
		strLength = 0;
	}
}

/***********************************************************
 * ������: CStr::CStr(const char*)
 * ��������: �������Ĺ��캯��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:58 
***********************************************************/ 
CStr::CStr(const char* str)
{
	strData = NULL;
	int length = strlen(str);

	strData = (char*)malloc(sizeof(char)*(length+1));
	ERRPRINT(NULL == strData, return, 0, "ConfigManager#CStr#CStr(), line %d", __LINE__);
	
	strncpy(strData, str, strlen(str));
	strData[length] = '\0';
	strLength = length;

#ifdef DEBUG_TEST
	printf("CStr:%p, strData:%p, Constructure\n", this, strData);
#endif
}

/***********************************************************
 * ������: CStr::CStr(const CStr& source)
 * ��������: �������캯��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 18:54 
***********************************************************/ 
CStr::CStr(const CStr& source)
{
	if (this == &source)
		return;

	if (source.GetLength() == 0)
	{
		strData = NULL;
		strLength = 0;
		return;
	}

	if (NULL != strData) free(strData);
	strData = (char*)malloc(sizeof(char)*(source.GetLength()+1));
	ERRPRINT(NULL == strData, return, 0, "ConfigManager#CStr#CStr(const CStr&), line %d", __LINE__);

	strncpy(strData, source.strData, source.GetLength());
	strData[source.GetLength()] = '\0';
	strLength = source.GetLength();
}

/***********************************************************
 * ������: CStr::setValue(char*)
 * ��������: ����CStr�����ֵ
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 19:07 
***********************************************************/ 
void CStr::setValue(char* val)
{
	if(NULL != strData)
		free(strData);

	int lengthVal = strlen(val);
	strData = (char*)malloc(sizeof(char)*(lengthVal + 1));
	ERRPRINT(NULL == strData, return, 0, "ConfigManager#CStr#setValue, line %d", __LINE__);

	strncpy(strData, val, lengthVal);
	strData[lengthVal] = '\0';
	strLength = lengthVal;
}

/***********************************************************
 * ������: CStr::ConvertInt()
 * ��������: ���ַ���ת������
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 20:35 
***********************************************************/ 
int  CStr::ConvertInt()
{
	return atoi(strData);
}

/***********************************************************
 * ������: CStr::SubString(int, int)
 * ��������: ��ȡ�ַ�������start �� end��start ���±� 1 ��ʼ
 * ����˵��: 
 * ����ֵ˵��: �����������˿ռ�malloc, �ں���������Ҫ�ͷ�
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 20:38 
***********************************************************/ 
char* CStr::SubString(int startpos, int endpos)
{
	if ((startpos == 0) && (startpos == endpos)) return NULL;

	ERRPRINT(startpos>endpos, return NULL, 0, "ConfigManager#CStr#SubString(), startpos should smaller than endpos, line %d", __LINE__);
	
	/* ��startpos �� endpos, ���� endpos-startpos+1 ���ַ�*/
	char* pstr = (char*)malloc(sizeof(char)*(endpos-startpos+2));
	ERRPRINT(NULL == pstr, return NULL, 0, "ConfigManager#CStr#SubString(), line %d", __LINE__);

	int i = 0, k = 0;
	for(i=startpos-1; i<=endpos-1; i++)
	{
		pstr[k++] = strData[i];
	}
	pstr[k] = '\0';

	return pstr;	
}

/***********************************************************
 * ������: CStr& operator=(const CStr& source)
 * ��������: =���������
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 20:30 
***********************************************************/ 
const CStr& CStr::operator=(const CStr& source)
{
	if (this != &source)
	{
		if (strData != NULL)
		{
			free(strData);
			strData = NULL;
			strLength = 0;
		}

		if (source.GetLength() == 0)
		{
			strData = NULL;
			strLength = 0;
			return *this;
		}
		strData = (char*)malloc(sizeof(char)*(source.GetLength() + 1));
		strncpy(strData, source.GetString(), source.GetLength());
		strData[source.GetLength()] = '\0';
		strLength = source.GetLength();

#ifdef DEBUG_TEST
		printf("CStr:%p, strData:%p, in operator=\n", this, strData);
#endif
	}
	return *this;
}

/***********************************************************
 * ������: myStrStr
 * ��������: ����dest�� src �е�һ�γ��ֵ�λ��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-27 13:33 
***********************************************************/ 
char* CStr::myStrStr(const char* src, const char* dest)
{
	int l2 = strlen(dest);

	if(0 == l2)
		return (char*)src;

	int l1 = strlen(src);
	while (l1 >= l2)
	{
		l1--;
		if (!memcmp(src, dest, l2))
			return (char*)src;
		src++;
	}

	return NULL;
}
