/*=========================================================
*	File name	��	LOG.H
*	Description	��	
*
*	Modify  	��	
*=========================================================*/
#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <memory.h>
#include "common/lock.h"
#include "global/globaldef.h"
#include "config/ConfigManager.h"
#include "common/error.h"
#include "common/myTime.h"

#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "log4cplus/helpers/stringhelper.h"
#include "log4cplus/loggingmacros.h"

#define LOGSTR_MAXLEN 4096 /* �����־�и�ʽ���ַ�������󳤶ȣ�����������Ƚ����ض� */

/* ��־����, DEBUG�����������־��Ϣ��INFO�������ʱϵͳ��־��Ϣ��ERROR���������־��Ϣ */
#define TRACE 1
#define DEBUG 2
#define INFO 3
#define WARN 4
#define ERROR 5
#define FATAL 6

#define LOG4CPLUS_
#define CPLUS_LOG(x, y, logger, desc) x##y(logger, desc)

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace log4cplus::thread;

class CLog  
{
public:
	CLog();
	~CLog();
	void Close(); /* �ر���־�ļ���� */

public:

	bool Open();

	/*a. ����澯��������־����ָ��Ϊ�գ�������һ�������ķ���ֵ���ɹ��ȣ�������Ϣ��Ҫͨ������ӿڽ��������
	  b. ���������־���ڵ��ԡ���һ��������ֵ�������ǳ������е�ʲô�ط���������ֵʲôʱ��ı�ȣ�һЩ�����ڴ���λ����Ϣͨ������ӿڽ��������
	  c. ���ϵͳ������־��ϵͳ������ģ��ֹͣ�������ȣ�һЩ��������״̬����Ϣ����ͨ������ӿڽ��������
	������
	1��	��־���� int logLevel
	2��	ģ���� 	char * ModuleName �����־ʱ����ģ��
	3��	���� 	char * ClassName �����־ʱ��������
	4��	������ 	char * FuncName �����־ʱ���ں�����
	5��	�����澯��Ϣ���� char * ErrorDescript 	����Ϣ��һ����Ҫ����
	*/
	void SysRunInfoDump(int logLevel, const char * moduleName, const char * className, const char * funcName, const char * logDescriptFmt,...);

	Logger GetLogger();
	char* GetLogDescription();

private:
	char m_logCfgPath[MAX_PATH];	// log4cplus ��־�����ļ�		
//	char* m_sysRunBuf;
	Logger m_logger;	//log4cplus ��־��¼����
private:
	//��ʽ����־��Ϣ
	void FormatSysRunInfo(const char * moduleName,const char * className,const char * funcName, char * logDescript, char* logstring);

};

extern CLog g_Log;

#define	DUMPSYSLOG g_Log.SysRunInfoDump	//���ϵͳ������־��

#endif // __LOG_H
