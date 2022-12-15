all: accelMagGyrotestt

accelMagGyrotestt : libMyPeri.a accelMagGyrotestt.c acc.h
	arm-linux-gnueabi-gcc accelMagGyrotestt.c -l MyPeri -L. -o accelMagGyrotestt -lpthread

libMyPeri.a : accelMagGyro.o
	arm-linux-gnueabi-ar rc libMyPeri.a accelMagGyro.o

accelMagGyro.o: acc.h accelMagGyro.c
	arm-linux-gnueabi-gcc -c accelMagGyro.c -o accelMagGyro.o

rm : 
	rm *.o
	rm libMyPeri.a
