#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "colorled.h"


int main(int argc, char *argv[]) {
if (argc != 4)
{ printf ("colorledtest.elf 0-100 0-100 0-100\r\n");
printf ("if value is 100 100 100 ==>  it means white color\r\n");
return 0; }
pwmLedInit();
pwmSetPercent(atoi(argv[1]),0);
pwmSetPercent(atoi(argv[2]),1);
pwmSetPercent(atoi(argv[3]),2);
pwmInactiveAll();
return 0;
}

