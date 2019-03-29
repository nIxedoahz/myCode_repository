/*=========================================================
*	�ļ���		��	MyStr.h
*	������		��	
*	��������	��	
*	����		��	
*
*	�޸ļ�¼  	��	
*=========================================================*/
#ifndef __MYSTR_H__
#define __MYSTR_H__

#include <stdarg.h>
#include <assert.h>
#include <malloc.h>

#include "common/error.h"

// �ַ���ʵ�ֵ��ڲ��ṹ
// ������ֱ�ӷ���!
/*********************************************************************
* Class:	CStr
* Purpose:	ʵ�ֶ�̬string
*********************************************************************/
class CStr
{

// ���ݿ鼰�ڲ����ʷ���
private:
		char* strData;
		int strLength;
		// ����, ����, ����
public:
		CStr();			//ȱʡ���캯��
		CStr(const char* str);
		CStr(const CStr& source);	//���ƹ��캯��
		~CStr();		//��������

// �����ԣ����ݣ����ȽϵĲ���
		bool IsEmpty() const;			//�ж��Ƿ�Ϊ��,Ϊ���򷵻�TRUE,
		int GetLength() const;			//ȡ�ó���
		
		const char* GetString() const;	//ȡ���ַ���,��\0����		
		char GetFirstChar() const;		//ȡ�õ�һ���ַ�

		char operator[](int idx) const;//ȡ��Ӧλ�õ��ַ�	
		char GetAt(int idx) const;		//ȡ��Ӧλ�õ��ַ�
		int  ConvertInt();	//��str�е�����ת������Ӧ������,���Զ��жϳ�str�е����ֲ���,���ص���ת���Ľ��,����ɲμ�atoi��MSDN����

		char* SubString(int startpos, int endpos); //���ش�start��end֮����ַ���
		char* myStrStr(const char* src, const char* dest); //��src��������һ�γ���dest��λ��
		/*void AddString(const CStr& obj);	//׷��CStr	*/
		/*void AddString(const char* s);		//׷��0�����ַ���	*/
		/*void AddChar(char ch);				//׷���ַ�*/

		void setValue(char* val);	

		const CStr& operator=(const CStr& source);  //'='���������,CStr
		void FreeData();
		};

/*********************************************************************
* Proc:		CStr::CStr()
* Purpose:	����յ�ʵ��
*********************************************************************/

inline CStr::CStr()
{
	strData = NULL;
	strLength = 0;

#ifdef DEBUG_TEST
	printf("CStr:%p, strData:%p, Constructure\n", this, strData);
#endif
}


/***********************************************************
 * ������: GetFirstChar
 * ��������: ��ȡ�ַ�����һ���ַ�,�����ļ��У���һ���ַ���;��ʾ����ע��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:43 
***********************************************************/ 
inline char CStr::GetFirstChar() const
{
	return strData[0];
}

/***********************************************************
 * ������: IsEmpty
 * ��������: �ж��ַ����Ƿ�Ϊ��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:42 
***********************************************************/ 
inline bool CStr::IsEmpty() const
{
	if(NULL == strData) return true;
	return strLength == 0;
}

/***********************************************************
 * ������: GetLength
 * ��������: ��ȡ�ַ����ĳ���
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:42 
***********************************************************/ 
inline int CStr::GetLength() const
{
	return strLength;
}


/***********************************************************
 * ������: CStr::operator[](int)
 * ��������: ���������[], ʹ��GetAt(),��ʹ���������
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:41 
***********************************************************/ 
inline char CStr::operator[](int idx) const
{
	return strData[idx];
}

/***********************************************************
 * ������: GetAt
 * ��������: ��ȡ�ַ���idx�����ַ�
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:40 
***********************************************************/ 
inline char CStr::GetAt(int idx) const
{
	return strData[idx];
}

/***********************************************************
 * ������: GetString
 * ��������: �����ַ���
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-24 17:40 
***********************************************************/ 
inline const char* CStr::GetString() const
{
	return strData;
}


#endif // __MYSTR_H__

