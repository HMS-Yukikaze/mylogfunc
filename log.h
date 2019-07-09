#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/times.h>
#include<stdarg.h>
#ifndef __LOG_H__
#define __LOG_H__
#define MyLogPath "MyLogPath"
int PLog(const char*file,const char*fun_name,int num,char *fmt,...);



#endif
