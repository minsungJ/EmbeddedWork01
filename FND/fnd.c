#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "fnd.h"
#define FND_DRIVER_NAME "/dev/perifnd"

void doHelp(void)
{
	printf("Usage:\n");
	printf("fndtest [option] [displaynum] [maxcounter]  >\n");
	printf("option   s  : static display  , displaynum range 0 ~ 999999\n");
	printf("option   t  ; time display  \n"); 
	printf("option   c  : count from 0 to maxcounter .\n");
	printf("option   o  : fnd off\n");
	printf("ex) fndtest s '123456'  ; display  '123456' \n");
	printf("ex) fndtest t 		;display current time \n");
	printf("ex) fndtest c 10 ; display counting number  from  0  to  10  with 1 Second interval.\n");
	printf("ex) fndtest 0		;display off \n");
}

#define ONE_SEG_DISPLAY_TIME_USEC	1000
// return 1 => success  , 0 => error

int fndDisp(int num , int dotflag) //0-999999 숫자, 비트로 인코딩된 dot on/off
{
	int fd;
	int temp,i;
	stFndWriteForm stWriteData;
	for (i = 0; i < MAX_FND_NUM ; i++ )
{
	stWriteData.DataDot[i] = (dotflag & (0x1 << i)) ? 1 : 0;
	stWriteData.DataValid[i] = 1;
}
// if 6 fnd
	temp = num % 1000000; stWriteData.DataNumeric[0]= temp /100000;
	temp = num % 100000; stWriteData.DataNumeric[1]= temp /10000;
	temp = num % 10000; stWriteData.DataNumeric[2] = temp /1000;
	temp = num %1000; stWriteData.DataNumeric[3] = temp /100;
	temp = num %100; stWriteData.DataNumeric[4] = temp /10;
	stWriteData.DataNumeric[5] = num %10;
	fd = open(FND_DRIVER_NAME,O_RDWR);
if ( fd < 0 )
{
	perror("driver open error.\n");
	return 0;
}
	write(fd, &stWriteData, sizeof(stFndWriteForm));
	close(fd);
	return 1;
}

int fndOff()
{
	int fd,i;
	stFndWriteForm stWriteData;
	
	for (i = 0; i < MAX_FND_NUM ; i++ )
	{
		stWriteData.DataDot[i] =  0;  
		stWriteData.DataNumeric[i] = 0;
		stWriteData.DataValid[i] = 0;
	}
	fd = open(FND_DRIVER_NAME,O_RDWR);
	if ( fd < 0 )
	{
		perror("driver open error.\n");
		return 0;
	}	
	write(fd,&stWriteData,sizeof(stFndWriteForm));
	close(fd);
	return 1;
}

