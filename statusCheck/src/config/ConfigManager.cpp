/**
 *filename: ConfigManager.cpp
 *func: define interface to get data from configure files
 *
 *
 */
 
#include "config/ConfigManager.h"
#include <fstream>

/* ȫ�ֱ�������ȡ�����ļ�·�� */
/* ���߳�ԭ�򣬽���ʹ��ȫ�ֱ��� */
/* be careful to use global variables when multi-threads */
/* static char g_szWorkPath[MAX_PATH]; */

/***********************************************************
 * ������: CConfigManager::CConfigManager()
 * ��������: ���캯��
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 11:49 
***********************************************************/ 
CConfigManager::CConfigManager()
{
	if(!Init())
		exit(EXIT_FAILURE);
}

/***********************************************************
 * ������: ~CConfigManager()
 * ��������: ��������
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 11:49 
***********************************************************/ 
CConfigManager::~CConfigManager()
{
	memset(m_szLocalCfgPath, 0, sizeof(m_szLocalCfgPath));
	/*memset(csList, 0, sizeof(csList));*/
}

/***********************************************************
 * ������: Init()
 * ��������: ��ʼ�����ù������
 * ����˵��: 
 * ����ֵ˵��: �ɹ�����1��ʧ�ܷ���0
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 15:30 
***********************************************************/ 
int CConfigManager::Init()
{
	memset(csList, 0, sizeof(csList));
	memset(m_szLocalCfgPath, 0, sizeof(m_szLocalCfgPath));

	char g_szWorkPath[MAX_PATH];
	memset(g_szWorkPath, 0, sizeof(g_szWorkPath)); //this is a global variable

	/* ��ȡ��ǰ����ľ���·����Ȼ��������·���ҵ������ļ�·��*/
	/*get_module_file_path( "downcheck", g_szWorkPath, MAX_PATH);*/

	/* getcwd to get current path will encounter problems */
	/* getcwd(g_szWorkPath, MAX_PATH); */
	/* ERRPRINT(NULL==g_szWorkPath, return 0, 0, "ConfigManager#CConfigManager#Init, line %d, g_szWorkPath [%s]", __LINE__, g_szWorkPath); */

	int cnt = readlink("/proc/self/exe", g_szWorkPath, MAX_PATH);
	ERRPRINT(cnt<0 || cnt>=MAX_PATH, exit(EXIT_FAILURE), 0, "CConfigManager#Init#line %d", __LINE__);

	//��ȡ��ǰĿ¼����·������ȥ��������
	int i;
	for (i=cnt; i>=0; i--)
	{
		if (g_szWorkPath[i] == '/')
		{
			g_szWorkPath[i] = '\0';
			break;
		}
	}

	strcat(g_szWorkPath,"/../config/");
	strncpy(m_szLocalCfgPath, g_szWorkPath, strlen(g_szWorkPath));

	ERRPRINT(access(m_szLocalCfgPath, F_OK)!=0, return 0, 0, "ConfigManager#CConfigManager#Init, line %d, m_szLocalCfgPath [%s]", __LINE__, m_szLocalCfgPath);

	return 1;
}

/***********************************************************
 * ������: GetValue(int CfgType, const char* cSection, const char* cItem, int& nVal)
 * ��������: 
 * ����˵��: 
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 15:05 
***********************************************************/ 
bool CConfigManager::GetValue(int CfgType, const char* cSection, const char* cItem, int& nVal)
{
#ifdef DEBUG_TEST
	printf("CfgType:%d, cSection:%s\n",CfgType, cSection); //log: find cSection in the config file INI_CFG_FILE_NAME[CfgType]
#endif

	/* ����Բ�ͬ�����ļ�ʱ��ʹ��ȫ�����ù��������Ҫ�� Load ֮ǰ�� csList �ÿ�*/
	/*memset(csList, 0, sizeof(csList));*/

	/* ƴ�������ļ�·�� */
	char szPath[MAX_PATH];
	strcpy(szPath, m_szLocalCfgPath);
	strcat(szPath, INI_CFG_FILE_NAME[CfgType]);
	Load(szPath);

	nVal = atoi(FindValue(cItem));
	return true;
}

bool CConfigManager::GetValue(int CfgType, const char* cSection, const char* cItem, char* strVal)
{
#ifdef DEBUG_TEST
	printf("CfgType:%d, cSection:%s\n",CfgType, cSection);
#endif
	
	char szPath[MAX_PATH];
	strcpy(szPath, m_szLocalCfgPath);
	strcat(szPath, INI_CFG_FILE_NAME[CfgType]);
	Load(szPath);

	/* �˴�����ʹ�� strcpy����Ϊ��src �ǿ�ʱ���ᷢ���δ��� segmentation fault */
	/* ʹ��strncpy���ܹ���֤�����ĳ��ȣ�ͬʱ��Ҫ���ƽ������ַ� */
	char* tmp = NULL;
	if ((tmp = FindValue(cItem)) == NULL)
		return false;
	strncpy(strVal, tmp, strlen(tmp));
	strVal[strlen(tmp)] = '\0';

	return true;
}

/***********************************************************
 * ������: Load(char* filename)
 * ��������: �������ļ�filename�����ݼ��ص�csList��
 * ����˵��: filename Ϊ�����ļ���
 * ����ֵ˵��: 
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 14:43 
***********************************************************/ 
bool CConfigManager::Load(char* filename)
{
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.good())
	{
		return false;
	}

	int i = 0;
	/* Start by wuzy 2016-06-12 15:31 */
	/* ��Ϊ֮ǰ��ֱ�ӽ�csList�ÿյģ�csList��CStr���͵����飬ͨ������=��������ƣ���malloc��̬�����ڴ�Ĳ���
	 * ���ԣ��ڶ�csList�ÿ�֮ǰ��Ҫ��֮ǰcsList��Ϊ�յ�ֵ�ͷŵ�
	 * ���򣬽�������ڴ�й© */
	while (csList[i].GetString())
	{
		csList[i].FreeData();
		i++;
	}
	/* End by wuzy 2016-06-12 15:31 */

	i = 0;
	char buf[1024];
	while (ifs.good())
	{
		ifs.getline(buf, sizeof(buf)-1);

		if(strcmp(buf, "") == 0) continue;

		CStr cs(buf);
		if(!cs.IsEmpty())
		{
			/* CStr��������=���������������Load������cs��ȫ����������������csList�����ֵȫ��Ϊ��*/
			csList[i++] = cs;
		}
	}
	return true;
}

/***********************************************************
 * ������: FindValue(const char* cItem)
 * ��������: ����������cItem�����ò���
 * ����˵��: 
 * ����ֵ˵��: �����ҵ������ò�����ֵ, NULL ��ʾû���ҵ�
 * �漰���ı�: 
 * ����: wzhenyu 
 * ʱ��: 2016-03-25 14:44 
***********************************************************/ 
char* CConfigManager::FindValue(const char* cItem)
{
	int i = 0;
	char* p = NULL;

	while(!csList[i].IsEmpty())
	{
		/*p = csList[i].myStrStr(csList[i].GetString(), cItem);*/
		p = strstr((char*)csList[i].GetString(), cItem);

		if(p != NULL)
		{
			if((csList[i].GetFirstChar() == ';')
					|| (csList[i].GetFirstChar() == '['))	//������ע�ͻ���[�ڵ�]������
			{
				i++;
				continue;
			}
			else if(*(p+strlen(cItem)) == '=')
			{
				p = p+strlen(cItem)+1;		//�������ںţ�Ϊ�˷��㣬�򵥣������ļ��в����ж���Ŀո�
				break;
			}
		}
		i++;
	}
	return p;
}
