/*=======================================================================
*	File name    : lock.h
*	Authored by    :	wzhenyu
*	Date	:
*	Description	:
*
*	Modify	:
*======================================================================*/
#ifndef __LOCK_H
#define __LOCK_H

#include <pthread.h>
#include <stdio.h>

class CLock
{
public:
	CLock();
	~CLock();
	int Lock();
	int Unlock();
	pthread_mutex_t m_Mutex;
};

/***********************************************************
 * ������: inline int CLock::Lock()
 * ��������:  
 * ����˵��: ���� 0 ��ʾ�������� 0 ����
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-04-14 17:02 
***********************************************************/ 
inline int CLock::Lock()
{
	return pthread_mutex_lock(&m_Mutex);
}

inline int CLock::Unlock()
{
	return pthread_mutex_unlock(&m_Mutex);
}

#endif    // #ifndef __LOCK_H

