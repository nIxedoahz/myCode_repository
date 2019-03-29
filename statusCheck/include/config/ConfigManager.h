/*=======================================================================
*	File name    :	ConfigManager.cpp
*	Authored by    :	wzhenyu
*	Date	:
*	Description	:
*
*	Modify	:
*======================================================================*/
#ifndef __CONFIGMANAGER_H__
#define __CONFIGMANAGER_H__


#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "config/MyStr.h"
#include "global/globaldef.h"

#define DOWNCHECK_CONFIG_INI 0

/*���������ļ�����*/
const char INI_CFG_FILE_NAME[2][64] = 
							{
								"downcheck_config.ini",
								""
							};

class CConfigManager
{
public:
	CConfigManager();
	~CConfigManager();

	bool GetValue(int CfgType, const char* cSection, const char* cItem, int& nVal); //��ȡ����
	bool GetValue(int CfgType, const char* cSection, const char* cItem, char* strVal);

	int Init();
	bool Load(char* filename); //���������ļ�
	char* FindValue(const char* cItem); //����������cItem�Ĳ�������
	int Start(); //����ϵͳ������������

private:
	char m_szLocalCfgPath[MAX_PATH+1];

public:
	CStr csList[512];	//ֱ�ӽ������ļ���ȡ���������У�Ȼ��ÿ��ֱ�Ӵ������в��ҾͿ���
};
extern CConfigManager *g_pConfigManager;

#endif    // #ifndef __CONFIGMANAGER_H__

