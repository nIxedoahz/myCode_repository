#ifndef __MY_TIME_H__
#define __MY_TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <string.h>
	
#define TIME_STRLEN 32
#define MAX_DATE "20990101000000" /* 2099-01-01 00:00:00 */
#define MAXDATETIME 2145801600  /* 2037-12-31 00:00:00*/

char* getCurTime();		/* �������ڸ�ʽΪ 2016-04-07 17:23:43 */
char* getCurTime2();	/* �������ڸ�ʽΪ 20160407172343*/
char* getCurDate();
char* getLastDays(int interval_time);	/* ����ǰ interval_time �������ʱ�䣬�����ʱ��ɸ��������ļ�����*/
int getUnixTime(const char * );
char* my_mktime(int time_sec);	/* ͨ��������ȡʱ�䣬ע��CST �� GMT ʱ�������� */


#ifdef __cplusplus
}
#endif

#endif
