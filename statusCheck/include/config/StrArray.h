#ifndef _STRARRAY_H_
#define _STRARRAY_H_

#include "MyStr.h"
#include <string.h>

class CStrArray  
{
public:
	CStrArray();
	~CStrArray();
    void Close();
	
public:
	int  Add(CStr *newstr);
	int  Add(const CStr &newstr);
	
	void SetAt( int nIndex, CStr* newstr );
	void SetAt( int nIndex,const  CStr& newstr );
	
    void InsertAt( int nIndex, CStr* newstr ); 
    void InsertAt( int nIndex,const  CStr& newstr ); 
	
	int  Remove(CStr *remstr);
    void RemoveAt(int nIndex);
	bool RemoveAll();
	
    int  GetSize() { return m_curno; }
	
	CStr* GetAt( int nIndex ) 
	{
		if(nIndex<m_curno&&nIndex>=0)
			return m_strTab[nIndex];
		return NULL;
	}
	
	CStr& GetAt2( int nIndex ) 
	{
		return *m_strTab[nIndex];
	}
	
	CStr*  operator[](int nIndex) 
	{
		if(nIndex<m_curno&&nIndex>=0)
			return m_strTab[nIndex];
		return NULL;
	}
	
	
private:
	int  m_curno;	//��ǰ������CStrԪ�صĸ���
	int  m_total;	//�������
	CStr **m_strTab;
};

#endif // _STRARRAY_H_

