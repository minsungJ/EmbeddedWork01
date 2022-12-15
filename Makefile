all: Temperaturetestt

Temperaturetestt : libMyPeri.a Temperaturetestt.c Temperature.h
	arm-linux-gnueabi-gcc Temperaturetestt.c -l MyPeri -L. -o Temperaturetestt -lpthread

libMyPeri.a : Temperature.o
	arm-linux-gnueabi-ar rc libMyPeri.a Temperature.o

Temperature.o: Temperature.h Temperature.c
	arm-linux-gnueabi-gcc -c Temperature.c -o Temperature.o

rm : 
	rm *.o
	rm libMyPeri.a
