#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdint.h>
#include<stdarg.h>
#include"log.h"
int PLog(const char*file,const char* fun_name,int num,char *fmt,...){
	int ret;
	va_list ap; 
	char sLocalTime[128];
	char sDatetime[128];
	char sLogName[128];
	struct tm *tmLocal=NULL;
	FILE *fp = NULL;
	memset(sLocalTime,0,sizeof(sLocalTime));
	memset(sDatetime,0,sizeof(sDatetime));
	memset(sLogName,0,sizeof(sLogName));
	//get log path
	char *PATH=NULL;
	PATH=getenv(MyLogPath);
	if(PATH == NULL){
		printf("get env PATH error!\n");
		return -1; 
	}else{
		//get time as the log name 
		time_t sTime = time(NULL);
		tmLocal=localtime(&sTime);
		strftime(sLocalTime,sizeof(sLocalTime),"%m%d%H%M%S",tmLocal);
		strftime(sDatetime,sizeof(sDatetime),"%Y%m%d%H%M%S",tmLocal);
		printf("system time:%s,date:%s\n",sLocalTime,sDatetime);
	
		sprintf(sLogName,"%s/%s.log",PATH,sDatetime);
		printf("sLogName: %s\n",sLogName);
		//open  a file
		fp=fopen(sLogName,"a+");
		if(fp==NULL){
			printf("open file error!\n");
			return -1;
		}

		//save log in file
		fprintf(fp,"[%s][%s][%d][%s]",sLocalTime,file,num,fun_name);
		va_start(ap, fmt);
		ret = vfprintf(fp, fmt, ap);
		va_end(ap);
		fclose(fp);
	}   
	return 0;
}




